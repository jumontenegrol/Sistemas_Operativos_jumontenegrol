const express = require('express');
const cors = require('cors');
const { buildIndex, searchRecord } = require('./hashUtils');

const app = express();
app.use(cors());
app.use(express.json());
app.use(express.static('public'));

app.post('/index', (req, res) => {
  const total = buildIndex();
  res.json({ message: `Índice creado con ${total} claves.` });
});

app.get('/search/:key', (req, res) => {
  const { key } = req.params;
  const result = searchRecord(key);
  if (result) {
    res.json({ found: true, record: result });
  } else {
    res.json({ found: false });
  }
});

const PORT = 3000;
app.listen(PORT, () => console.log(`Servidor activo en http://localhost:${PORT}`));
