## Coisas que precisamos citar

### Introdução

- Leve embasamento teórico sobre redes. 
- Introdução sobre ns-3 OK
- Introdução sobre o problema OK

### Exercício proposto

- Explicar bem os cenários do exercício
- Fazer um desenho pra explicar a topologia assim como nos slides
- Descrever as aplicações usadas (Bulk, onOff, Sink)
- Descrever a mobilidade (tamanho, etc)
- Citar o SSID

### Metodologia

- Explicar sobre as aplicações usadas
    - Qual aplicação TCP/UDP?
    - Atributos das aplicações
        - Ex:bulkSendClient.SetAttribute("MaxBytes", ns.UintegerValue(4096))
- Explicar sobre os campos usados do XML para criação das métricas
    - Dentro deste tópico, bom falar sobre o parse_flowmon.py
- Explicar cálculo dos dados dos gráficos (provavelmente será uma média das métricas de cada nó)
- Configurações da máquina do experimento
    - A princípio será:
        - Ubuntu 22.04
        - 12th Gen Intel(R) Core(TM) i5-1235U
        - 8GB RAM DDR4

- Como executar o script run.py
