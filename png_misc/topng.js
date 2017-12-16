const fs = require('pn/fs');
const svg2png = require("svg2png");
const path = require('path');


let train_dir_path = '../output/train/svg/'
let train_output_dir_path = '../output/train/png/'

let test_dir_path = '../output/test/svg/'
let test_output_dir_path = '../output/test/png/'

init(train_dir_path, train_output_dir_path)
init(test_dir_path, test_output_dir_path)

function init(input_dir_path, output_dir_path){

    fs.readdir(input_dir_path, (err, files) => {
        files.forEach(file => {
          //console.log(file);
          convert(file, input_dir_path,output_dir_path);
        });
    })
}

function convert(filename, input_dir_path, output_dir_path){
    let output_filename = filename.replace(".svg", ".png");
    let input_path = input_dir_path + filename;
    console.log(input_path);
    fs.readFile(input_path)
    .then(svg2png)
    .then(buffer => fs.writeFile(output_dir_path + output_filename, buffer))
    .catch(e => console.error(e));

}

