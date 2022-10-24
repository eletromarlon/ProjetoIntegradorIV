setInterval(() => {
    getTime()
    getData()
}, 100)

/**Função para o relógio */
function getTime(){
    const relogio = document.getElementById('relogio')
    const tempo = new Date() 
    var hora = (tempo.getHours() < 10? '0' + tempo.getHours() : tempo.getHours())
    var min = (tempo.getMinutes() < 10? '0' + tempo.getMinutes() : tempo.getMinutes())
    var turno = (hora < 12? 'am' : 'pm')

    relogio.innerHTML = `${hora}:${min}${turno}`
}

/**Função para retornar a data atual */
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

/** Função de abrir e fechar sidebar */
function botaoSideBar(){
    let btn_svg = document.querySelector('.botao-svg')
    let sidebar = document.querySelector('.sidebar')

    sidebar.classList.toggle('active')
    btn_svg.classList.toggle('active')  
}
window.onload = () => {
    for (let i = 0; i < 3; i++) {
       mudaCor(0, i)      
    }
}

function mudaCor(semaforo, cor){
    const cores = ['##32FA12', '#FAE212', '#DB2B2B'] /**Verde, Amarelo, Vermelho */
    const coresNome = ['Verde', 'Amarelo', 'Vermelho']

    let circles = document.querySelectorAll('.status-light')
    let spanTextos = document.querySelectorAll('.color')

    circles[semaforo].style.backgroundColor = cores[cor]
    spanTextos[semaforo].innerHTML = coresNome[cor]
    
    console.log(circles[semaforo], spanTextos[semaforo])
}