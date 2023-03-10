let shared_memory = require("..");
try{
    let memory1=shared_memory.createMemory("MEMORY1");
    let memory2=shared_memory.createMemory("MEMORY2");
    //console.log(memory1,memory2)
    console.log("Press key for Write.")
    shared_memory.getch();
    shared_memory.writeStringToMemory(memory1,"From 1st");
    console.log("Write Completed.Press key for read From memory2.");
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