import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// Interface para matrícula GUI
interface MatriculaGUI {
    void matricular(String codAluno, String codCurso, String turma);
    void exibirStatus(String turma);
}

class EscolaFacade implements MatriculaGUI {
    private Map<String, Curso> cursos;
    private Map<String, Aluno> alunos;
    private Map<String, Turma> turmas;

    private static EscolaFacade facadeInstance;

    private EscolaFacade() {
        this.cursos = new HashMap<>();
        this.alunos = new HashMap<>();
        this.turmas = new HashMap<>();
    }

    public static EscolaFacade getInstance(){
        if(EscolaFacade.facadeInstance == null)
            EscolaFacade.facadeInstance = new EscolaFacade();

        return facadeInstance;
    }

    @Override
    public void matricular(String codAluno, String codCurso, String turma) {
        Curso curso = cursos.get(codCurso);
        Aluno aluno = alunos.get(codAluno);

        if (curso != null && aluno != null) {
            Turma novaTurma = turmas.getOrDefault(turma, new Turma(curso));
            novaTurma.addAluno(aluno);
            turmas.put(turma, novaTurma);
            System.out.println("Matrícula realizada.");
        } else {
            System.out.println("Curso ou aluno não encontrado.");
        }
    }

    @Override
    public void exibirStatus(String turma) {
        Turma targetTurma = turmas.get(turma);
        if (targetTurma != null) {
            Curso curso = targetTurma.getCurso();
            List<Aluno> alunos = targetTurma.getAlunos();
            System.out.println("Status da turma: " + curso.getNome());
            System.out.println("Alunos matriculados:");
            for (Aluno aluno : alunos) {
                System.out.println("- " + aluno.getNome() + " (" + aluno.getMatricula() + ")");
            }
        } else {
            System.out.println("Turma não encontrada.");
        }
    }

    public void registrarCurso(String codigo, String nome) {
        cursos.put(codigo, new Curso(nome));
    }

    public void registrarAluno(String codigo, String nome, String matricula) {
        alunos.put(codigo, new Aluno(nome, matricula));
    }
}

// Classe Curso
class Curso {
    private String nome;

    public Curso(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }
}

// Classe Aluno
class Aluno {
    private String nome;
    private String matricula;

    public Aluno(String nome, String matricula) {
        this.nome = nome;
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }

    public String getMatricula() {
        return matricula;
    }
}

// Classe Turma
class Turma {
    private Curso curso;
    private List<Aluno> alunos;

    public Turma(Curso curso) {
        this.curso = curso;
        this.alunos = new ArrayList<>();
    }

    public void addAluno(Aluno aluno) {
        alunos.add(aluno);
    }

    public Curso getCurso() {
        return curso;
    }

    public List<Aluno> getAlunos() {
        return alunos;
    }
}

public class Main {
  public static void main(String[] args){
    EscolaFacade firstSchool = EscolaFacade.getInstance();
    EscolaFacade secondSchool = EscolaFacade.getInstance();
    EscolaFacade thirdSchool = EscolaFacade.getInstance();

    System.out.println(firstSchool);
    System.out.println(secondSchool);
    System.out.println(thirdSchool);
  }
}
