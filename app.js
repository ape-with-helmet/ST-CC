const express=require("express")
const cors=require("cors")
const mongoose = require('mongoose')
const { validEmail, validPassword } = require('./valid');
mongoose.connect("mongodb://localhost:27017/ded")
.then(()=>{
    console.log("Connected")
})
.catch(()=>{
    console.log("failed")
})
const collection=require("./mongoose")
const app=express()
app.use(express.json())
app.use(express.urlencoded({extended:true}))
app.use(cors())

app.get("/",cors(),(req,res)=>{

})

app.post("/create",async(req,res)=>{
    const {email,password}=req.body
    
    const data={
        email:email,
        password:password
    }
    if (!email || !password){
        console.log("Please provide all information !")
    }
    let valEmail = validEmail(email);
    if (!valEmail) {
        console.log("please enter valid email: ")
    }
    let valPass = validPassword(password);
    if (!valPass) {
        console.log("please enter valid password: ")
    }
    //unique validation
    let uniqueEmail = await collection.findOne({email})
    if (uniqueEmail) {
        console.log('mail exists')
        return res.send({message : "Email already exists!"})
    }
    let createUs = await collection.create(data)
        console.log(createUs)
})

app.post("/delete",async(req,res)=>{
    const {email}=req.body
    
    const data={
        email:email,
    }
    let uniqueEmail = await collection.findOne({email})
    if (!uniqueEmail) {
        console.log('invalid email')
    }
    await collection.deleteMany(data)
})

app.post("/login",async(req,res)=>{
    const {email,password}=req.body
    
    const data={
        email:email,
        password:password
    }
    let uniqueEmail = await collection.findOne({email,password})
    if (!uniqueEmail) {
        console.log('invalid credentials');
        // alert("Wrong username or password")
        return res.send({message : "Login error"})
    }
    console.log('Success login')
})

app.listen(8000,()=>{
    console.log("port connected")
})