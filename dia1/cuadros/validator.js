function validate(world, callbacks) {
  var a, b, c, d, n;
  for (a = world.i; !(world.walls(a, world.j) & 8); --a) {}
  for (b = world.i; !(world.walls(b, world.j) & 2); ++b) {}
  for (c = world.j; !(world.walls(world.i, c) & 1); --c) {}
  for (d = world.j; !(world.walls(world.i, d) & 4); ++d) {}
  
  var beepers = []
  var total_beepers = 0;
  for (var i = a; i <= b; ++i) {
    beepers[i - a] = []
    for (var j = c; j <= d; ++j) {
      beepers[i - a][j - c] = world.buzzers(i, j);
      total_beepers += beepers[i - a][j - c];
    }
  }
  
  n = b - a + 1;
  var left = [], down = [];
  for (var i = 0; i < n; ++i) {
    left[i] = [], down[i] = [];
    for (var j = 0; j < n; ++j)
      left[i][j] = 0, down[i][j] = 0;
  }
  
  var percentage = (total_beepers * 100) / (n * n);
  percentage = Math.round(percentage * 100) / 100;
  
  for (var i = 0; i < n; ++i) {
    if (!beepers[i][0]) left[i][0] = 1;
    if (!beepers[0][i]) down[0][i] = 1;
    for (var j = 1; j < n; ++j) {
      if (beepers[i][j]) left[i][j] = 0;
      else left[i][j] = left[i][j - 1] + 1;
      if (beepers[j][i]) down[j][i] = 0;
      else down[j][i] = down[j - 1][i] + 1;
    }
  }
  
  var impossibru = false;
  for (var i = 0; i < n && !impossibru; ++i) {
    for (var j = 0; j < n && !impossibru; ++j) {
      if (beepers[i][j]) continue;
      for (var k = 1; k < n && !impossibru; ++k) {
        if (i - k < 0 || j - k < 0) break;
        if (beepers[i - k][j] || beepers[i][j - k]) break;
        if (left[i - k][j] > k && down[i][j - k] > k)
          impossibru = true;
      }
    }
  }
  
  if (!impossibru) {
    var msg_valid = 'La solución es válida';
    var msg_used = 'Zumbadores usados: ' + total_beepers;
    var msg_percentage = 'Porcentaje: ' + percentage + '%';
    alert(msg_valid);
    alert(msg_used);
    alert(msg_percentage);
  } else {
    var msg_valid = 'La solución es inválida';
    alert(msg_valid);
  }
}