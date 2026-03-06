docs/research_landscape.md

#	Research Landscape: Mussel-Based Water Quality Monitoring Systems

## 	1. Introduction

Bivalve mollusks (mussels, oysters, clams) are widely used as biological indicators of water quality due to their sensitivity to environmental changes and pollutants. Their behavioral responses — especially the opening and closing of shells (valve gape behavior) — provide a measurable signal of ecological stress.

Biological Early Warning Systems (BEWS) based on mollusks have been developed in several countries to provide continuous monitoring of aquatic environments, complementing traditional chemical analysis methods.

This document provides a brief overview of existing biomonitoring systems and research relevant to the OpenCV-WASM EcoMonitor concept.

##	2. Classical Mussel Biomonitoring Systems

### 	2.1 Musselmonitor®

One of the earliest automated systems for monitoring water quality using mussels is the Mosselmonitor.

Principle

Sensors are attached to both halves of the mussel shell.
The distance between the shells is measured using electromagnetic coils.

**The system records:**

-	valve opening angle

-	behavioral rhythm

-	sudden closure events

If several mussels close simultaneously, the system generates an alarm.

The technology is widely used in laboratory experiments and water monitoring installations.

### 2.2 SYMBIO Biomonitoring System

Another widely deployed system is the SYMBIO Biomonitoring System developed in Poland.

**Architecture**

-	8 freshwater mussels placed in a flow-through tank

-	sensors attached to shells

-	behavioral monitoring in real time

-	automated alarm generation

The system is used in water treatment facilities and monitors drinking water for millions of people.

### 	2.3 molluSCAN-eye®

A more recent generation of biomonitoring solutions is molluSCAN-eye.

**Key features:**

-	real-time monitoring of shell movements

-	cloud-connected system

-	visualization dashboards

-	environmental impact monitoring for industry

The system was developed in cooperation with laboratories of the CNRS and the University of Bordeaux.

## 	3. Scientific Monitoring Programs

###	3.1 Mussel Watch Program

A large-scale environmental monitoring program is the Mussel Watch Program operated by the National Oceanic and Atmospheric Administration.

Since 1986 it has monitored pollution in coastal waters by analyzing contaminants accumulated in mussels and sediments across hundreds of sites.

Unlike real-time monitoring systems, this program focuses on long-term environmental assessment.

##	4. Emerging Research Directions

Recent studies explore several new technological directions:

### 	4.1 Wireless biosensor networks

Experimental projects such as Cybermussels propose connecting mussel sensors into distributed networks for environmental monitoring and data collection.

**These systems may combine:**

-	RFID identification

-	environmental sensors

-	camera monitoring

-	centralized databases.

### 	4.2 Machine learning for environmental prediction

Modern research explores applying machine learning to predict environmental risks affecting mussel populations and water toxicity.

**These approaches combine:**

-	historical environmental datasets

-	biological indicators

-	predictive modeling.

##	5. Positioning of the OpenCV-WASM EcoMonitor Project

Most existing biomonitoring systems rely on direct physical sensors attached to shells.

The proposed OpenCV-WASM EcoMonitor concept explores an alternative approach:

Computer vision based biomonitoring

**Key ideas:**

-	camera-based observation of mussels

-	image analysis using OpenCV

-	lightweight deployment through WebAssembly

-	browser-based visualization

-	cloud-enabled monitoring architecture

Potential advantages:

-	non-invasive measurement

-	lower hardware complexity

-	scalable remote monitoring

-	easier integration with web infrastructure.

##	6. Research Gap

Although many biomonitoring systems exist, most rely on specialized hardware sensors.

**The following areas remain relatively underexplored:**

-	computer vision analysis of mussel behavior

-	web-based biomonitoring systems

-	lightweight edge deployments using WebAssembly

-	open-source ecological monitoring platforms.

These areas motivate the development of the OpenCV-WASM EcoMonitor project.
