# Collision Avoidance – TTool

A simple **Collision Avoidance system** modeled using **TTool / AVATAR** and implemented in C.

## 🎥 Demo

[![Collision Avoidance – TTool](https://img.youtube.com/vi/Z7NEGpGa5yQ/maxresdefault.jpg)](https://youtu.be/Z7NEGpGa5yQ)

## 🏗️ System Architecture

![Block Diagram](Collision_Avoidance_Block_Diagram.png)

The system consists of:

- **CA** – Collision Avoidance
- **US** – Ultrasonic Sensor
- **DC_Motor** – Motor control

## 🔄 State Machines

### Collision Avoidance

![CA State Machine](CA_State_Machine_Diagram.png)

### DC Motor

![DC Motor State Machine](DC_Motor_State_Machine_Diagram.png)

### Ultrasonic

![Ultrasonic State Machine](US_State_Machine_Diagram.png)

## 📊 Dynamic Sequence

![Sequence Diagram](Sequence_Diagram.png)

## 💻 C Implementation

The corresponding C implementation is available in:

[Code_Implementation/](./Code_Implementation/)

![Code Implementation](Code_Implementation.png)