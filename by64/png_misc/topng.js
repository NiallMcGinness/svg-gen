const fs = require('pn/fs');
const svg2png = require("svg2png");
const path = require('path');


var dir_path = '/home/nm/proj/gh/svg-gen/by64/output/train/svg/'
var output_dir_path = '/home/nm/proj/gh/svg-gen/by64/output/train/png/'




async function load_batch_names(batch) {
    return new Promise((resolve, rejectj) => {
         batch.forEach(file => {
         console.log(file);
        //convert_p(file);
      }).then(load());
     
    });
   // await timer(2000);
    
}


var files_s = fs.readdirSync(dir_path)

console.log(` length of array ${ files_s.length  } `)

let total_len = files_s.length
var batch_size = 100;
let batches = total_len / batch_size;

for( let i = 0; i < batches; i++) {
    let start_index = i * batch_size;
    let batch = files_s.slice(start_index, start_index + batch_size + 1 );
    //load_batch(batch)
    timed_load_batch(batch)
}

function timed_load_batch(batch){

    load_batch_names(batch)
}
//load()

async function read(){
    return new Promise((resolve, reject) => {

    });
}

function convert(filename){

        let output_filename = filename.replace(".svg", ".png");
        let input_path = dir_path + filename;

        //console.log(input_path);
        fs.readFile(input_path)
        .then(svg2png)
        .then(buffer => fs.writeFile(output_dir_path + output_filename, buffer))
        .catch(e => console.error(e));

}

async function convert_p(filename){
    
            let output_filename = filename.replace(".svg", ".png");
            let input_path = dir_path + filename;
    
            //console.log(input_path);
            return fs.readFile(input_path)
            .then(svg2png)
            .then(buffer => fs.writeFileSync(output_dir_path + output_filename, buffer))
            .catch(e => console.error(e));
    
    }




   
async function load () {
    for (var i = 0; i < 3; i++) {
     console.log(i);
     await timer(10000);
     }
}


function timer(ms){
    return new Promise(r=>setTimeout(r,ms));
}