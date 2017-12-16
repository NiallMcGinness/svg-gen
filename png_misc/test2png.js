const fs = require('pn/fs');
const svg2png = require("svg2png");
const path = require('path');

/*
var filePath = "../output/train/0.svg";
var resolvedPath = path.resolve(filePath);
console.log(resolvedPath);

fs.readFile(resolvedPath)
    .then(svg2png)
    .then(buffer => fs.writeFile("../output/train/png/noaxis2tr.png", buffer))
    .catch(e => console.error(e));
*/

var dir_path = '/home/nm/proj/gh/svg-gen/output/test/svg/'
var output_dir_path = '/home/nm/proj/gh/svg-gen/output/test/png/'

fs.readdir(dir_path, (err, files) => {
    files.forEach(file => {
      //console.log(file);
     convert(file);
    });
})

function convert(filename){
    let output_filename = filename.replace(".svg", ".png");
    let input_path = dir_path + filename;
    console.log(input_path);
    fs.readFile(input_path)
    .then(svg2png)
    .then(buffer => fs.writeFile(output_dir_path + output_filename, buffer))
    .catch(e => console.error(e));

}
