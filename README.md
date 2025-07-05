
# 🤖 Program-Miro

Control software pentru un robot cu două motoare, bazat pe un algoritm PID simplificat, destinat deplasării autonome în funcție de senzori laterali.

---

## 🎯 Scop

Proiectul controlează mișcarea unui robot cu două roți, folosind date de la senzori digitali plasați pe partea stângă și dreaptă. Obiectivul este menținerea direcției corecte și adaptarea la schimbări de zonă.

---

## ⚙️ Funcționalități

- Citirea senzorilor digitali (stânga/dreapta)
- Ajustarea vitezei motoarelor folosind algoritmul **PID**
- Comunicare serială cu driverul de motoare prin comenzi binare
- Detectarea schimbării de zonă și recalibrarea traiectoriei

---

## 🧠 Algoritm

```cpp
adjustment = KP * error + KD * (error - lastError);
```

Unde eroarea este diferența dintre poziția curentă (`zone`) și obiectivul dorit (`GOAL`), ajustând diferențiat viteza motoarelor stânga/dreapta.

---

## 📦 Componente

- 2 senzori digitali (IR pentru linie)
- Microcontroler compatibil Arduino
- Driver motoare

---
