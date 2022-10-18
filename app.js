const express = require('express')
const path = require('path')
const expressLayout = require('express-ejs-layouts')
const router = require('./routes/routes')

const app = express()

app.set('view engine', 'ejs')

app.use(express.static(__dirname + "/public"));

app.use(router.routes)

app.listen(3000 , () => {
    console.log('Servidor rodando na porta 3000')
})