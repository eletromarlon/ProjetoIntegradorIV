const express = require('express')

const welcome = (req,res) => {
    res.render('index')
    //res.send('Tô aqui')
}

const contact = (req, res) =>{
    res.render('contact')
}

const dasboard = (req, res) =>{
    res.render('dashboard')
}

module.exports = {
    welcome,
    contact,
    dasboard
}