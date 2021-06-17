#!/usr/bin/node
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function getChatacter (character) {
  return new Promise((resolve, reject) => {
    request(character, function (error, response, body) {
      if (error) {
        reject(error);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
}

request(url, async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const chars = JSON.parse(body).characters;
    for (let n = 0; n < chars.length; n++) {
      const character = await getChatacter(chars[n]);
      console.log(character);
    }
  }
});
