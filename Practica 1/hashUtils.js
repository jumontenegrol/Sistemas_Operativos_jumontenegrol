const fs = require('fs');
const path = require('path');

const DATA_FILE = path.join(__dirname, 'dataset', 'data.csv');
const INDEX_FILE = path.join(__dirname, 'dataset', 'index.json');

function simpleHash(key) {
  let hash = 0;
  for (let i = 0; i < key.length; i++) {
    hash = (hash * 31 + key.charCodeAt(i)) % 100000;
  }
  return hash;
}

function buildIndex() {
  const data = fs.readFileSync(DATA_FILE, 'utf8').split('\n');
  const index = {};

  for (let i = 0; i < data.length; i++) {
    const line = data[i];
    const fields = line.split(',');
    const key = fields[0]; // usa la columna que quieras como clave
    const hash = simpleHash(key);
    index[hash] = i; // guarda la línea en la que está el registro
  }

  fs.writeFileSync(INDEX_FILE, JSON.stringify(index, null, 2));
  return Object.keys(index).length;
}

function searchRecord(key) {
  const index = JSON.parse(fs.readFileSync(INDEX_FILE));
  const hash = simpleHash(key);
  const lineNumber = index[hash];
  if (lineNumber === undefined) return null;

  const data = fs.readFileSync(DATA_FILE, 'utf8').split('\n');
  return data[lineNumber];
}

module.exports = { buildIndex, searchRecord };
