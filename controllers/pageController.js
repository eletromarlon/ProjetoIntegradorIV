const express = require('express')

const welcome = (req,res) => {
    res.render('welcome')
    //res.send('Tô aqui')
}

const contact = (req, res) =>{
    res.render('contact')
}

const dasboard = (req, res) =>{
    res.render('index')
}

module.exports = {
    welcome,
    contact,
    dasboard
}