# Mathematics Behind the Radar Simulator

## 1. Range Measurement
R = (c × τ) / 2

## 2. Doppler Effect
fd = 2 × v / λ

## 3. Complex IQ Signal
s(t) = A × e^(j × 2π(fc(t-delay) + fd×t))

## 4. FFT
Converts time domain IQ samples → frequency domain (Range & Doppler)

## 5. CA-CFAR
Adaptive threshold = α × average(noise cells)
