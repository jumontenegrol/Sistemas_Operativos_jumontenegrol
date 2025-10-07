const output = document.getElementById('output');
const searchKey = document.getElementById('searchKey');

document.getElementById('indexBtn').addEventListener('click', async () => {
  output.textContent = 'Creando índice...';
  const res = await fetch('/index', { method: 'POST' });
  const data = await res.json();
  output.textContent = data.message;
});

document.getElementById('searchBtn').addEventListener('click', async () => {
  const key = searchKey.value.trim();
  if (!key) return alert('Ingresa una clave para buscar.');

  output.textContent = 'Buscando...';
  const res = await fetch(`/search/${key}`);
  const data = await res.json();

  if (data.found) {
    output.textContent = `Registro encontrado:\n${data.record}`;
  } else {
    output.textContent = 'No se encontró el registro.';
  }
});
