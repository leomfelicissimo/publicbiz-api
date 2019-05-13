# PublicBiz Api

Esta Api foi criada com o objetivo de conhecer a linguagem ReasonML e sua utilização expondo uma WebApi real com conexão em um repositório de dados.

## Getting Started

Siga as instruções abaixo para executar o projeto localmente na sua máquina para desenvolvimento e testes.

### Pré-requisitos

Para execução deste projeto localmente certifique-se que você tenha instalado:

- [NodeJs LTS](https://nodejs.org/en/): Obtenha a versão LTS do Node para garantir o suporte a alguns recursos utilizados;

- [MongoDb](https://www.mongodb.com/download-center): Este projeto utiliza como repositório de dados o MongoDb. Portanto, você precisa garantir que ele esteja sendo executado localmente.

### Instalando e Executando Localmente

#### Instalando o compilador e dependências
Após clonar o repositório, tenha certeza de que ele seja seu diretório atual e execute o comando para instalar as dependências:
```
npm install
```

O BuckleScript foi adicionado como uma dependência local. Isso significa que tudo deveria funcionar corretamente. Mas sabemos como é esse mundo de desenvolvimento de software... Caso tenha problemas para execução do código ReasonML, tente instalar o _bs-plataform_ globalmente.


```
npm install -g bs-platform
```

#### Preparando o banco de dados para execução local
Sugiro que você utilize o Docker para a execução do MongoDb localmente.
- [Docker](https://docs.docker.com/install/): Instruções para instalar e executar o Docker localmente.
```
# Após instalar o docker, você pode utilizar o seguinte comando para ter um container executando o mongodb localmente:

$ docker run --name mongodb -p 27017:27017 -d mongo:bionic

# Uma vez que o container estiver sendo executado, conecte-se nele para a execução dos passos seguintes:

$ docker exec -it mongodb bash
```

Com o MongoDb instalado e sendo executado localmente, será necessário criar o banco de dados e a collection (isso poderia ser feito mais facilmente com uma imagem pronta, mas não tenho tempo pra tudo isso agora).
```
# Inicie uma nova sessão do MongoShell

$ mongo

# Crie o banco de dados (basta usá-lo na verdade)

$ use publicbiz

# Crie a collection de teste

$ db.createCollection("templates")

# Insira alguns dados para testar

$ db.templates.insert({ name: "Template 1" })
$ db.templates.insert({ name: "Template 2" })
$ db.templates.insert({ name: "Template 3" })
```

Agora que já instalamos o compilador e temos o banco de dados executando localmente, basta executar o servidor:

```
$ npm run serve
```

## Testando

Faça uma chamada http no endereço principal para obter uma mensagem básica de que tudo está funcionando corretamente.
```
$ curl http://localhost:9000/
```

Faça uma segunda chamada que conecta no MongoDb usando o módulo ReasonML que criei e obtém os documentos da collection _templates_ da base _publicbiz_:
```
$ curl http://localhost:9000/mongodb
```

## Tecnologias, Bibliotecas e Frameworks:

* [ReasonML](https://reasonml.github.io/en/) - eason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems.
* [NodeJs](https://nodejs.org/en/) - Node.js® is a JavaScript runtime built on Chrome's V8 JavaScript engine.
* [MongoDb](https://www.mongodb.com/) - MongoDB’s flexible document data model makes working with data intuitive, whether you’re building an app from scratch or updating an existing one.
* [ExpressJs](https://expressjs.com/) - Fast, unopinionated, minimalist web framework for Node.js

## Authors

* **Leonardo Felicissimo** - [leomfelicissimo](https://github.com/leomfelicissimo)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
