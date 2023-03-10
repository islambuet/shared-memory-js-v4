var shared_memory = require("..");
try{
    let memory1=shared_memory.createMemory("MEMORY1");      
    console.log("Press key for Write.")
    shared_memory.getch();
    shared_memory.writeStringToMemory(memory1,"Hello there. I am shaiful.Writing from js");
    console.log("Press key for read.");
    shared_memory.getch();
    let message=shared_memory.readStringFromMemory(memory1);
    console.log(message);
    shared_memory.getch();
    console.log("Press key for End.");
    shared_memory.getch();    
}
catch(e){
    console.log("catch: " + e)
}

//console.log(sm);