let shared_memory = require("..");
try{
    let memory1=shared_memory.connectMemory("MEMORY1");
    let memory2=shared_memory.connectMemory("MEMORY2");
    //console.log(memory1,memory2)

    console.log("Press key for read From memory1.");
    shared_memory.getch();
    let message=shared_memory.readStringFromMemory(memory1);
    console.log(message);
    console.log("Press key for write to  memory2.");
    shared_memory.getch();
    shared_memory.writeStringToMemory(memory2,"2nd");
    console.log("Write done.Press key for End.");
    shared_memory.getch();
}
catch(e){
    console.log("catch: " + e)
}

//console.log(sm);