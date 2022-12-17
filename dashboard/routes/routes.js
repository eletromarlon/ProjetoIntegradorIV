const express =  require('express')
const {welcome, contact, dasboard} = require('../controllers/pageController')
const router = express.Router()

router.get('/', welcome)
router.get('/contact', contact)
router.get('/dashboard', dasboard)

module.exports = {routes: router}