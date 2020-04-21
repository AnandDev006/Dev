const axios = require('axios');
const cheerio = require('cheerio');
var fs = require('fs');

const CONTEST_URL = 'https://codeforces.com/contest/1343';

let getTestCaseFromProblemHtml = (dir, html) => {

  fs.copyFileSync(`${dir}/../template.cpp`, `${dir}/main.cpp`);
  data = [];
  const $ = cheerio.load(html);
  $('div.input').each((i, elem) => {
    data[i] = {
      ...data[i],
      input: $(elem).text().substring('Input'.length),
    };
  });
  $('div.output').each((i, elem) => {
    data[i] = ({
      ...data[i],
      output: $(elem).text().substring('Output'.length),
    });
  });
  console.log(data);
  data.forEach((test, i) => {
    fs.writeFile(`${dir}/main.${i}.inp`, test.input, function(err) {
      if(err) {
          console.log(err);
      }
      console.log(`The file ${dir}/main.${i}.inp was saved!`);
    }); 
    fs.writeFile(`${dir}/main.${i}.oac`, test.output, function(err) {
      if(err) {
          console.log(err);
      }
      console.log(`The file ${dir}/main.${i}.oac was saved!`);
    }); 
  })
  console.log(data);
}

function getTestCaseFromProblemUrl(url) {
  var dir = `./${url.substring(url.lastIndexOf('/')+1)}`;

  if (!fs.existsSync(dir)){
      fs.mkdirSync(dir);
  }

  axios.get(url)
    .then(response => {
      // console.log(response);
      getTestCaseFromProblemHtml(dir, response.data);
    }
    )
    .catch(err => console.log(err));
}

// getTestCaseFromProblemUrl(url);

// ''
let getTotalProblemsFromContestHtml = (html) => {
  data = [];
  const $ = cheerio.load(html);
  console.log('parsing');
  $('tr td.id a').each((i, elem) => {
    problem_url = 'https://codeforces.com/' + $(elem).attr('href')
    console.log(problem_url);
    getTestCaseFromProblemUrl(problem_url);
  });
}

axios.get(CONTEST_URL)
    .then(response => {
      // console.log(response);
      getTotalProblemsFromContestHtml(response.data);
    });