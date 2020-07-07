# Documentação da API

## Rotas de Inscrições

### GET

```js
router.get("/", verify, inscriptionsController.index);
```

**Descrição:**

- Lista todas as inscrições cadastradas no banco.

**URL:**

- `localhost:3333/api/inscriptions/`

**Parametros esperados:**

- Token de validação que deve ser passado no header.

**Retorno:**

- Lista de todas as inscrições cadastradas no banco.

```js
router.get("/:id", verify, inscriptionsController.show);
```

**Descrição:**

- Lista uma inscrição específica.

**URL:**

- `localhost:3333/api/inscriptions/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id da inscrição que deseja-se obeter deve ser passado pela propria URL, Ex: `localhost:3333/api/inscriptions/53bsd2n`

**Retorno:**

- A inscrição que possui o id passado pela URL, caso a mesma exista.

### POST

```js
router.post(
  "/",
  multer(multerConfig("zip")).single("file"),
  inscriptionsController.store
);
```

**Descrição:**

- Cadastra uma nova inscrição no banco.

**URL:**

- `localhost:3333/api/inscriptions/`

**Parametros esperados:**

- Body do tipo multipart-form com os campos `name`, `email`, `phone` e `file`.
  [Aqui](https://github.com/HenriqueCruz5341/UFES/blob/18123a7950d42a8a4b1c895193d4ef46a2fa6026/web/sitePet/web/src/App.js#L51) está um exemplo de como deve ser mais ou menos.

**Retorno:**

- Caso tudo ocorra bem, será retornado o id da nova inscrição, caso contrário, uma mensagem descrevendo o que houve de errado.

### DELETE

```js
router.delete("/:id", verify, inscriptionsController.destroy);
```

**Descrição:**

- Deleta uma inscrição específica do banco.

**URL:**

- `localhost:3333/api/inscriptions/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id da inscrição que deseja-se deletar deve ser passado pela propria URL, Ex: `localhost:3333/api/inscriptions/53bsd2n`

**Retorno:**

- Caso tudo ocorra bem, será retornado a inscrição que foi deletada, caso contrário, uma mensagem descrevendo o que houve de errado.

### PATCH

```js
router.patch(
  "/acceptInscription/:id",
  verify,
  inscriptionsController.updateInscription
);
```

**Descrição:**

- Altera o estado de `accept` de uma inscrição

**URL:**

- `localhost:3333/api/inscriptions/acceptInscription/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id da inscrição que deseja-se alterar deve ser passado pela propria URL, Ex: `localhost:3333/api/inscriptions/acceptInscriptions/53bsd2n`.
- Body do tipo json com o campo `accept`.

**Retorno:**

- Caso tudo ocorra bem, será retornado uma mensagemd e sucesso, caso contrário, uma mensagem descrevendo o que houve de errado.

## Rotas de Documentos

### GET

```js
router.get("/", documentsController.index);
```

**Descrição:**

- Lista todos os documentos cadastrados no banco.

**URL:**

- `localhost:3333/api/documents/`

**Parametros esperados:**

- Nenhum

**Retorno:**

- Lista de todos os documentos cadastrados no banco.

```js
router.get("/:id", documentsController.show);
```

**Descrição:**

- Lista um documento específico.

**URL:**

- `localhost:3333/api/documents/:id`

**Parametros esperados:**

- id do documento que deseja-se obeter deve ser passado pela propria URL, Ex: `localhost:3333/api/documents/53bsd2n`

**Retorno:**

- O documento que possui o id passado pela URL, caso o mesmo exista.

### POST

```js
router.post("/", verify, documentsController.store);
```

**Descrição:**

- Cadastra um novo documento no banco.

**URL:**

- `localhost:3333/api/documents/`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- Body do tipo JSON com o campo `title`.

**Retorno:**

- Caso tudo ocorra bem, será retornado o id do novo documento, caso contrário, uma mensagem descrevendo o que houve de errado.

### PATCH

```js
router.patch(
  "/addFile/:id",
  verify,
  multer(multerConfig("pdf")).single("file"),
  documentsController.addFile
);
```

**Descrição:**

- Adiciona um novo arquivo na lista de um documento específico.

**URL:**

- `localhost:3333/api/documents/addFile/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- Body do tipo multipart-form com o campo `file`.
  [Aqui](https://github.com/HenriqueCruz5341/UFES/blob/18123a7950d42a8a4b1c895193d4ef46a2fa6026/web/sitePet/web/src/App.js#L51) está um exemplo de como deve ser mais ou menos.
- id do documento que deseja-se adicionar um novo arquivo deve ser passado pela propria URL, Ex: `localhost:3333/api/documents/addFile/53bsd2n`

**Retorno:**

- Caso tudo ocorra bem, será retornado o documento alterado, caso contrário, uma mensagem descrevendo o que houve de errado.

```js
router.patch("/removeFile/:id", verify, documentsController.removeFile);
```

**Descrição:**

- Remove um arquivo de um documento específico.

**URL:**

- `localhost:3333/api/documents/removeFile/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- Body do tipo JSON com o campo `idFile`
- id do documento que deseja-se remover um arquivo deve ser passado pela propria URL, Ex: `localhost:3333/api/documents/removeFile/53bsd2n`

**Retorno:**

- Caso tudo ocorra bem, será retornado o documento alterado, caso contrário, uma mensagem descrevendo o que houve de errado.

### PUT

```js
router.put("/:id", verify, documentsController.update);
```

**Descrição:**

- Altera o campo `title` de um documento

**URL:**

- `localhost:3333/api/documents/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id do documento que deseja-se alterar deve ser passado pela propria URL, Ex: `localhost:3333/api/documents/53bsd2n`.
- Body do tipo json com o campo `title`.

**Retorno:**

- Caso tudo ocorra bem, será retornado o documento alterado, caso contrário, uma mensagem descrevendo o que houve de errado.

### DELETE

```js
router.delete("/:id", verify, documentsController.destroy);
```

**Descrição:**

- Deleta um documento e todos os seus arquivos do banco.

**URL:**

- `localhost:3333/api/documents/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id do documento que deseja-se deletar deve ser passado pela propria URL, Ex: `localhost:3333/api/documents/53bsd2n`

**Retorno:**

- Caso tudo ocorra bem, será retornado o documento que foi deletada, caso contrário, uma mensagem descrevendo o que houve de errado.

## Rotas de Notícias (Ainda não está pronta)

### GET

```js
router.get("/", newsController.index);
```

**Descrição:**

- Lista todas as notícias cadastradas no banco.

**URL:**

- `localhost:3333/api/news/`

**Parametros esperados:**

- Token de validação que deve ser passado no header.

**Retorno:**

- Lista de todas as notícias cadastradas no banco.

```js
router.get("/:id", newsController.show);
```

**Descrição:**

- Lista uma notícia específica.

**URL:**

- `localhost:3333/api/news/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id da notícia que deseja-se obeter deve ser passado pela propria URL, Ex: `localhost:3333/api/news/53bsd2n`

**Retorno:**

- A notícia que possui o id passado pela URL, caso a mesma exista.

### POST

```js
router.post("/", verify, newsController.store);
```

**Descrição:**

- Cadastra uma nova notícia no banco.

**URL:**

- `localhost:3333/api/news/`

**Parametros esperados:**

- Body do tipo multipart-form com os campos `name`, `email`, `phone` e `file`.
  [Aqui](https://github.com/HenriqueCruz5341/UFES/blob/18123a7950d42a8a4b1c895193d4ef46a2fa6026/web/sitePet/web/src/App.js#L51) está um exemplo de como deve ser mais ou menos.

**Retorno:**

- Caso tudo ocorra bem, será retornado o id da nova inscrição, caso contrário, uma mensagem descrevendo o que houve de errado.

### PUT

```js
router.put("/:id", verify, newsController.update);
```

**Descrição:**

- Altera os campos de uma notícia que ja foi cadastrada.

**URL:**

- `localhost:3333/api/news/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id da notícia que deseja-se alterar deve ser passado pela propria URL, Ex: `localhost:3333/api/news/53bsd2n`
- Body do tipo multipart-form com os campos `title`, `text` e `file`.
  [Aqui](https://github.com/HenriqueCruz5341/UFES/blob/18123a7950d42a8a4b1c895193d4ef46a2fa6026/web/sitePet/web/src/App.js#L51) está um exemplo de como deve ser mais ou menos.
- Todos os campos devem estar preenchidos com as informações finais da notícia.

**Retorno:**

- Caso tudo ocorra bem, será retornado uma mensagem de sucesso, caso contrário, uma mensagem descrevendo o que houve de errado.

### DELETE

```js
router.delete("/:id", verify, newsController.destroy);
```

**Descrição:**

- Deleta uma notícia específica do banco.

**URL:**

- `localhost:3333/api/news/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id da notícia que deseja-se deletar deve ser passado pela propria URL, Ex: `localhost:3333/api/news/53bsd2n`

**Retorno:**

- Caso tudo ocorra bem, será retornado a notícia que foi deletada, caso contrário, uma mensagem descrevendo o que houve de errado.

## Rotas de Login

### GET

```js
router.get("/", loginController.login);
```

**Descrição:**

- Cria um token para a sessão de um petiano.

**URL:**

- `localhost:3333/api/login/`

**Parametros esperados:**

- Credenciais do petiano devem der passados pelo header [dessa forma](https://pt.stackoverflow.com/questions/323579/axios-basic-auth-como-passar-usuario-e-senha-para-a-api).

**Retorno:**

- Caso as credenciais do petiano estejam corretas, retorna um token válido, caso contrário, uma mensagem descrevendo o que houve de errado.

## Rotas de Arquivos

### GET

```js
router.get("/", fileController.index);
```

**Descrição:**

- Lista todos os arquivos cadastrados no banco.

**URL:**

- `localhost:3333/api/file/`

**Parametros esperados:**

- Nenhum.

**Retorno:**

- Lista de todos os arquivos cadastrados no banco.

```js
router.get("/downloadDocument/:id", fileController.downloadDocument);
```

**Descrição:**

- Retorna o arquivo de um documento do PET específico que está cadastrado no banco, para que o download do mesmo possa ser efetuado.

**URL:**

- `localhost:3333/api/file/downloadDocument/:id`

**Parametros esperados:**

- id do campo `file` do documento que deseja-se fazer o download deve ser passado pela propria URL, Ex: `localhost:3333/api/file/downloadDocument/53bsd2n`

```json
  "document": {
    "_id": "5ea46187ab1b8825fa6ad89b",
    "owner": "Molibe",
    "file": {
      "_id": "5ea46187ab1b8825fa6ad89a", este é o campo que deve ser passado
      "name": "Android-introducao.pdf",
      "size": 3015686,
      "key": "dbe32b8dbc64f0bb6f81b67427cd4e9d-Android-introducao.pdf",
      "createdAt": "2020-04-25T18:11:14.160Z",
      "__v": 0
    },
    "__v": 0
}
```

**Retorno:**

- O arquivo que foi solicitado.

```js
router.get("/downloadInscription/:id", fileController.downloadInscription);
```

**Descrição:**

- Retorna o arquivo de uma inscrição específica que está cadastrado no banco, para que o download do mesmo possa ser efetuado.

**URL:**

- `localhost:3333/api/file/downloadInscription/:id`

**Parametros esperados:**

- Token de validação que deve ser passado no header.
- id do campo `file` da inscrição que deseja-se fazer o download deve ser passado pela propria URL, Ex: `localhost:3333/api/file/downloadInscription/53bsd2n`

```json
"inscriptions": [
    {
      "accepted": false,
      "_id": "5eaa0991415a907122286841",
      "name": "Henrique",
      "email": "henrique@email.com",
      "phone": "28999720210",
      "file": {
        "_id": "5eaa0990415a907122286840",  este é o campo que deve ser passado
        "name": "arquivos.zip",
        "size": 288250,
        "key": "bb982e16c8216dc451894935138d455b-arquivos.zip",
        "createdAt": "2020-04-29T23:11:12.882Z",
        "__v": 0
      },
      "__v": 0
    }
  ]
```

**Retorno:**

- O arquivo que foi solicitado.

## Rotas de Contato

### POST

```js
router.post("/", contactContoller.sendEmail);
```

**Descrição:**

- Envia um email para o email do PET com a mensagem que o usuário quiser.

**URL:**

- `localhost:3333/api/contact/`

**Parametros esperados:**

- Body json com os campos `name`, `subject` e `text`.

**Retorno:**

- Caso tudo ocorra bem, será retornado o objeto criado para o envio do email, caso contrário, uma mensagem descrevendo o que houve de errado.

## Considerações

### Middleware verify

As rotas que possuem um `verify`, por exemplo, `router.get("/", verify, inscriptionsController.index)`,
o token deve ser passado pelo header [dessa forma](https://www.schoolofnet.com/forum/topico/configurando-a-autenticacao-com-o-axios-1616).

### Envio de arquivos

- Os arquivos de documentos do PET devem estar no formato de PDF.
- Os arquivos de documentos das inscrições devem estar compactados em formato ZIP.

### Download dos arquivos

Um exemplo de como se fazer o download dos arquivos retornados pela api pode ser encontrado [aqui](https://github.com/HenriqueCruz5341/UFES/blob/master/web/sitePet/web/src/App.js#L24)
