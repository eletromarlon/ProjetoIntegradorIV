setInterval(() => {
    getTime()
    getData()
}, 100)

function getTime(){
    const relogio = document.getElementById('relogio')
    const tempo = new Date() 
    var hora = (tempo.getHours() < 10? '0' + tempo.getHours() : tempo.getHours())
    var min = (tempo.getMinutes() < 10? '0' + tempo.getMinutes() : tempo.getMinutes())
    var turno = (hora < 12? 'am' : 'pm')

    relogio.innerHTML = `${hora}:${min}${turno}`
}

function getData(){
    const data_text = document.querySelectorAll('.data')
    const data = new Date()
    var dia = data.getDate()
    var mes = data.getMonth() + 1
    var ano =  data.getFullYear()

    data_text.forEach(element => {
        element.innerHTML = `Hoje, ${dia}-${mes}-${ano}`
    });
}

function botaoSideBar(){
    let btn_svg = document.querySelector('.botao-svg')
    let sidebar = document.querySelector('.sidebar')

    sidebar.classList.toggle('active')
    btn_svg.classList.toggle('active')
    console.log(sidebar)
    console.log(btn_svg)
    
}