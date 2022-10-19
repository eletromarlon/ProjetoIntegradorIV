setInterval(() => {
    const relogio = document.getElementById('relogio')
    const tempo = new Date() 
    var hora = (hora < 10? '0' + tempo.getHours() : tempo.getHours())
    var min = (min < 10? '0' + tempo.getMinutes() : tempo.getMinutes())
    var turno = (hora < 12? 'am' : 'pm')

    relogio.innerHTML = `${hora}:${min}${turno}`
}, 1000)