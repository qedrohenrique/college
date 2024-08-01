# java.lang.Math

Não faz sentido ser um Singleton, haja visto que não teria problemas uma classe que com um método que retorna números aleatórios terem várias instâncias.
Seria interessante um Singleton caso quisessemos uma seed única.

# PrinterManager

Considerando que mais de um PrinterManager para uma única impressora poderia causar inconsistências na impressão, essa classe deve ser um Singleton.

# PrintSpooler

Essa classe faz sentido ser um Singleton, considerando que não podemos ter vários Spoolers, uma vez que caso isso acontecesse, diferentes PrintStream poderiam tomar vez na PrinterManager.

# PrintStream

Não faz sentido ser Singleton, já que podemos querer limpar ou instanciar streams de saída a medida que ela é manipulada.

# java.lang.System

Não faz sentido ser Singleton também, uma vez que faz mais sentido ela ser uma classe estática, pois não é interessante termos que depender de um objeto para fazer operacões de entrada e saída.
