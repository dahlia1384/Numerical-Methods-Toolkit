import 'dart:html';
import 'dart:math' as math;

void main() {
  querySelector('#runNewton')!.onClick.listen((_) => runNewton());
  querySelector('#runRk4')!.onClick.listen((_) => runRk4());
}

void runNewton() {
  final x0 = _numValue('#newtonX0');
  final maxIters = _intValue('#newtonIters');
  final tol = _numValue('#newtonTol');

  double x = x0;
  var converged = false;
  var k = 0;
  var residual = double.infinity;

  for (k = 1; k <= maxIters; k++) {
    final fx = _f(x);
    final dfx = _df(x);
    residual = fx.abs();
    if (dfx == 0) break;

    final x1 = x - fx / dfx;
    if ((x1 - x).abs() <= tol * (1 + x1.abs())) {
      x = x1;
      converged = true;
      break;
    }
    x = x1;
  }

  _setOut(
    '#newtonOut',
    'root ≈ ${x.toStringAsPrecision(12)}\n'
    'iterations: $k\n'
    'converged: $converged\n'
    'residual: ${residual.toStringAsExponential(3)}',
  );
}

void runRk4() {
  final dt = _numValue('#rkDt');
  final steps = _intValue('#rkSteps');
  double t = 0.0;
  double y = 0.5;

  final rows = <String>['t\ty'];
  rows.add('${t.toStringAsFixed(2)}\t${y.toStringAsFixed(6)}');

  for (var i = 0; i < steps; i++) {
    final k1 = _ode(t, y);
    final k2 = _ode(t + 0.5 * dt, y + 0.5 * dt * k1);
    final k3 = _ode(t + 0.5 * dt, y + 0.5 * dt * k2);
    final k4 = _ode(t + dt, y + dt * k3);

    y += (dt / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
    t += dt;
    rows.add('${t.toStringAsFixed(2)}\t${y.toStringAsFixed(6)}');
  }

  _setOut('#rkOut', rows.join('\n'));
}

double _f(double x) => math.pow(x, 3).toDouble() - x - 2;
double _df(double x) => 3 * x * x - 1;
double _ode(double t, double y) => y - t * t + 1;

double _numValue(String selector) {
  final input = querySelector(selector) as InputElement;
  return double.tryParse(input.value ?? '') ?? 0.0;
}

int _intValue(String selector) {
  final input = querySelector(selector) as InputElement;
  return int.tryParse(input.value ?? '') ?? 0;
}

void _setOut(String selector, String value) {
  final pre = querySelector(selector) as PreElement;
  pre.text = value;
}
