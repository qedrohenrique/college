def get_data():
  # Vertices

  agencias = [
    "RUA SANTA CLARA, 245", #
    "AVENIDA RUI BARBOSA, 2376", #
    "RUA RIACHUELO, 57",
    "AVENIDA ANDROMEDA, 1469", #
    "RUA SABARA, 30",
    "RUA EZEQUIEL ALVES GRACIANO, 140",
    "RUA QUINZE DE NOVEMBRO, 259",
    "AVENIDA DOUTOR NELSON D AVILA, 90",
    "RUA LOANDA, 895",
    "RUA GOIANIA, 15", #
  ]

  pessoas_fisicas = [
    "RUA MATIAS PERES, 364",
    "RUA DA ALEGRIA, 39",
    "RUA CAPARAÓ, 370",
    "RUA ITUIUTABA, 50",
    "RUA PIMENTEIRAS, 322",
    "RUA CARVALHO DE ARAÚJO, 106 ",
    "RUA SAMUEL ANTÔNIO RODRIGUES, 197",
  ]

  empresas = [
    "EMBRAER BRG. FARIA LIMA, 2170",
    "AKAER AV. CESARE MONSUETO GIULIO LATTES, 501",
    "DEDÉ CELLAV. ANDRÔMEDA, 654",
  ]

  outros = [
    "UNESP AV. ENGENHEIRO FRANCISO JOSÉ LONGO, 777"
  ]

  vertexes = agencias + pessoas_fisicas + empresas + outros

  # Arestas

  edges = []

  for agencia in agencias:
    for pessoa in pessoas_fisicas:
      edges.append((agencia, pessoa))

  for agencia in agencias:
    for empresa in empresas:
      edges.append((agencia, empresa))

  for agencia in agencias:
    for outro in outros:
      edges.append((agencia, outro))

  return edges, vertexes

def get_enumerated_data():
  agencias = [
    "RUA SANTA CLARA, 245", #
    "AVENIDA RUI BARBOSA, 2376", #
    "RUA RIACHUELO, 57",
    "AVENIDA ANDROMEDA, 1469", #
    "RUA SABARA, 30",
    "RUA EZEQUIEL ALVES GRACIANO, 140",
    "RUA QUINZE DE NOVEMBRO, 259",
    "AVENIDA DOUTOR NELSON D AVILA, 90",
    "RUA LOANDA, 895",
    "RUA GOIANIA, 15", #
  ]

  pessoas_fisicas = [
    "RUA MATIAS PERES, 364",
    "RUA DA ALEGRIA, 39",
    "RUA CAPARAÓ, 370",
    "RUA ITUIUTABA, 50",
    "RUA PIMENTEIRAS, 322",
    "RUA CARVALHO DE ARAÚJO, 106 ",
    "RUA SAMUEL ANTÔNIO RODRIGUES, 197",
  ]

  empresas = [
    "EMBRAER BRG. FARIA LIMA, 2170",
    "AKAER AV. CESARE MONSUETO GIULIO LATTES, 501",
    "DEDÉ CELLAV. ANDRÔMEDA, 654",
  ]

  outros = [
    "UNESP AV. ENGENHEIRO FRANCISO JOSÉ LONGO, 777"
  ]

  vertexes = agencias + pessoas_fisicas + empresas + outros
  vertexes_as_indexes = {vertex: index for index, vertex in enumerate(vertexes)}

  # Arestas

  edges = []

  for agencia in agencias:
    for pessoa in pessoas_fisicas:
      edges.append((vertexes_as_indexes[agencia], vertexes_as_indexes[pessoa]))

  for agencia in agencias:
    for empresa in empresas:
      edges.append((vertexes_as_indexes[agencia], vertexes_as_indexes[empresa]))

  for agencia in agencias:
    for outro in outros:
      edges.append((vertexes_as_indexes[agencia], vertexes_as_indexes[outro]))

  vertex_indexes = {index: vertex for index, vertex in enumerate(vertexes)}

  return vertex_indexes, edges

def get_sub_data():
  # Vertices

  agencias = [
    "RUA SANTA CLARA, 245", #
    "AVENIDA RUI BARBOSA, 2376", #
    "RUA RIACHUELO, 57",
    "AVENIDA ANDROMEDA, 1469", #
    "RUA SABARA, 30",
    "RUA EZEQUIEL ALVES GRACIANO, 140",
    "RUA QUINZE DE NOVEMBRO, 259",
    "AVENIDA DOUTOR NELSON D AVILA, 90",
    "RUA LOANDA, 895",
    "RUA GOIANIA, 15", #
  ]

  pessoas_fisicas = [
    "RUA MATIAS PERES, 364",
    "RUA DA ALEGRIA, 39",
    "RUA CAPARAÓ, 370",
    "RUA ITUIUTABA, 50",
    "RUA PIMENTEIRAS, 322",
    "RUA CARVALHO DE ARAÚJO, 106 ",
    "RUA SAMUEL ANTÔNIO RODRIGUES, 197",
  ]

  empresas = [
    "EMBRAER BRG. FARIA LIMA, 2170",
    "AKAER AV. CESARE MONSUETO GIULIO LATTES, 501",
    "DEDÉ CELLAV. ANDRÔMEDA, 654",
  ]

  outros = [
    "UNESP AV. ENGENHEIRO FRANCISO JOSÉ LONGO, 777"
  ]

  vertexes = agencias + pessoas_fisicas + empresas + outros

  # Arestas

  edges = []

  for agencia in agencias:
    for pessoa in pessoas_fisicas:
      edges.append((agencia, pessoa))

  for agencia in agencias:
    for empresa in empresas:
      edges.append((agencia, empresa))

  for agencia in agencias:
    for outro in outros:
      edges.append((agencia, outro))

  return edges, vertexes

def get_enumerated_sub_data():
  agencias = [
    "RUA SANTA CLARA, 245", #
    "AVENIDA RUI BARBOSA, 2376", #
    "RUA RIACHUELO, 57",
  ]

  pessoas_fisicas = [
    "RUA MATIAS PERES, 364",
    "RUA FAKE, 123321"
    "RUA DA ALEGRIA, 39",
    "RUA CAPARAÓ, 370",
  ]

  empresas = [
    "EMBRAER BRG. FARIA LIMA, 2170",
  ]

  outros = [
    "UNESP AV. ENGENHEIRO FRANCISO JOSÉ LONGO, 777"
  ]

  vertexes = agencias + pessoas_fisicas + empresas + outros
  vertexes_as_indexes = {vertex: index for index, vertex in enumerate(vertexes)}

  # Arestas

  edges = []

  for agencia in agencias:
    for pessoa in pessoas_fisicas:
      edges.append((vertexes_as_indexes[agencia], vertexes_as_indexes[pessoa]))

  for agencia in agencias:
    for empresa in empresas:
      edges.append((vertexes_as_indexes[agencia], vertexes_as_indexes[empresa]))

  for agencia in agencias:
    for outro in outros:
      edges.append((vertexes_as_indexes[agencia], vertexes_as_indexes[outro]))


  vertex_indexes = {index: vertex for index, vertex in enumerate(vertexes)}

  return vertex_indexes, edges