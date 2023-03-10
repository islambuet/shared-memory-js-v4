let shared_memory = require("..");
const {value: array_01_value} = require("../array_01");
try{
  let memory1=shared_memory.createMemory("MEMORY1");
  let memory2=shared_memory.createMemory("MEMORY2");  
  let array_01_value=  require('../array_01.js').value;
  for(let i=0;i<2;i++){
    array_01_value.ulong_msCounter++;
    console.log("Press key for Write Array 01.")
    shared_memory.getch();
    shared_memory.writeArray01ToMemory(memory1,array_01_value);
    console.log("Press key for read Array02.");
    shared_memory.getch();
    let array_02_value_current=shared_memory.readArray02FromMemory(memory2);
    console.log(array_02_value_current);
  }

    console.log("Press key for Close memmory.");
    shared_memory.getch();
    shared_memory.closeMemory(memory1);
    shared_memory.closeMemory(memory2);
    console.log("Press key for End.");
shared_memory.getch();
}
catch(e){
    console.log("catch: " + e)
}

//console.log(sm);