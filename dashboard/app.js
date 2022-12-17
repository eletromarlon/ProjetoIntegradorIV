const express = require('express')
const http = require('http')
const router = require('./routes/routes')
const { SerialPort, ReadlineParser } = require('serialport')
const { Server } = require('socket.io')

const app = express()
const server = http.createServer(app)
const io = new Server(server)

/*const serialPort = new SerialPort({path:'/dev/ttyUSB0', baudRate: 9600})
const parser = new ReadlineParser()

serialPort.pipe(parser)

parser.on('data', (data) => {
    console.log(data)
})*/

app.set('view engine', 'ejs')

app.use(express.static(__dirname + "/public"));

app.use(router.routes)

io.on('connection', (socket) => {
    let msg =  {
        'TotalDeVeiculos': 100,
        'Cruzamento1': {
            'Semaforo1':{
                'cor': 0,
                'tempoDeAbertura': 10
            },
            'Semaforo2':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
            'Semaforo3':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
            'Semaforo4':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
        },
        'Cruzamento2': {
            'Semaforo5':{
                'cor': 0,
                'tempoDeAbertura': 10
            },
            'Semaforo6':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
            'Semaforo7':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
            'Semaforo8':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
        },
        'Cruzamento3': {
            'Semaforo9':{
                'cor': 0,
                'tempoDeAbertura': 10
            },
            'Semaforo10':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
            'Semaforo11':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
            'Semaforo12':{
                'cor': 2,
                'tempoDeAbertura': 10
            },
        },
        
    }

    socket.emit("hello", msg, (response) => {
        console.log(response); // "got it"
      });
})

server.listen(3000 , () => {
    console.log('Servidor rodando na porta 3000')
})