window.onload = () =>{
    speedCanvas()
    canvaAmount()
}


function speedCanvas(){
    const ctx = document.getElementById('canvaSpeed').getContext('2d');
    const myChart = new Chart(ctx, {
        type: 'line',
        data: {
            labels: ['0M', '10M', '20M', '30M', '40M', '50M', '60M'],
            datasets: [{
                data: [
                    {x: '0M', y: '10'}, 
                    {x: '10M', y: '25'},
                    {x: '20M', y: '25'},
                    {x: '30M', y: '40'},
                    {x: '40M', y: '3'},
                    {x: '50M', y: '60'},
                    {x: '60M', y: '50'},
                ],
                backgroundColor: [
                    'hsl(112, 96%, 53%)',
                    
                ],
                borderColor: [
                    'hsl(112, 96%, 53%)',
                ],
                borderWidth: 1,
                cubicInterpolationMode: 'monotone'
            }]
        },
        options: {
            scales: {
                y: {
                    beginAtZero: true
                }
            },
            plugins: {
                legend: {
                    display: false,
                }
            }
            
        }
    });

}

function canvaAmount(){
    const ctx = document.getElementById('canvaAmount').getContext('2d');
    const myChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ['10M', '20M', '30M', '40M', '50M', '60M'],
            datasets: [{
                data: [
                    {x: '10M', y: '10'}, 
                    {x: '20M', y: '25'},
                    {x: '30M', y: '125'}
                ],
                backgroundColor: [
                    '#FFE605',
                    
                ],
                borderColor: [
                    '#FFE605',
                ],
                borderWidth: 1,
                borderRadius: 30,
                barThickness: 15,
                borderSkipped: 'middle', 
            }]
        },
        options: {
            scales: {
                y: {
                    beginAtZero: true
                },
                x: {
                    beginAtZero: true
                }
            },
            plugins: {
                legend: {
                    display: false,
                }
            }

        }
    });

}

