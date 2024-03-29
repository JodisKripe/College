# Overview
![[Pasted image 20240120211645.png]]

# What is malicious software
A software which dies some malicious things on a computer like deleting files, stealing data etc
Also called Malware
### Types:
- Virus: replicates itself into other programs, when executed, the malicious code runs.
- Worm: Can execute on its own. In dependant program
- Keyloggers: Grab keystrokes
- Spyware: Collect information from one computer and transmits to another computer illegally.
- Ransomware: Lock files on the computer. Asks for money to decrypt it.
# Insider Attack
- Generated by someone who is a part of the development team
	- programmer working on project
	- embedded malware can come as part of Os or as part of application installed later
- Backdoor
	- provides non-conventional access to a resource
	- hidden feature to gain access or manipulate something on the target system
	- provide remote access to computers
	- can have both legitimate and illegitimate use
- Logic bomb
	- if(trigger-condition == true)
		- {action}
	- Once the trigger point is met, then the malicious portion of the code is excuted.
	- ![[Pasted image 20240120212748.png]]
## Defense
- Multiple people should maintain systems( multiple sysadmins etc )
- Code Walkthrough
	- One programmer has to explain logic of code written of other programmer to keep both the programmers aware of what the program is actually doing.
	- Code Review before push is also correct.
- Least Privilege Principle
	- can reduce damage
	- less collateral
- Monitor Employee Behaviour

# Virus
![[Pasted image 20240120213258.png]]
usually embedded within a legitimate program
### Phases
- Dormant Phase
- Propogation Phase: replication and propogation to other systems
- Triggering Phase: the Action phase is trigger by an action
- Action phase: Actual damage is done
## Defense:
- Detection: Antivirus
- Evasion detection ( malware authors try to evade detection by Antivirus etc )
	- Encryption ( encrypt the malicious code, decrypt it right before execution )
	- Polymorphic Virus: From system one, when it goes to system 2, the program its encrypted with key k1, when propogated to system 3 its encrypted with key k2 so all the copies of the virus look different and have no common signatures pertaining to the malicious code.
	- Metamorphic Virus: Using other obfuscation techniques while propogating.
- Signatures
	- In order signatures: when we see some bits in order, then we detect it as a virus
	- Conjunction signatures: jumbled order of bits is still detected it as a virus
	- Probabilistic signatures: probability of virus is established based on how many out of the bits are detected (% overlap ).

# What can they do
- Send copies of itself
- Take actions without user knowledge
	- steal data
	- modify data
	- delete data
	- generate network traffic
	- harvest passwords
	- encrypt files and data

## Flood Based DDoS Attack
![[Pasted image 20240120214722.png]]
The in-genuine traffic from the bots overwhelm the resources of the victim and the genuine users and their genuine traffic is not handled

## Syn Flood attack
Abuses the Three way handshake process

Usually,
SYN -> SYN ACK -> ACK

whenever a SYN packet is received, a TCB (Transmisison control block) is created on the receiver to store information about the connection. Its size varies from 250-1000 bytes.

Attacker sends a lot of SYN packets to the victim in succession and no Ack packets

so,
SYN -> SYNACK -> SYN -> SYNACK and so on

Hence, a lot of TCBs are created on the victim's system.

## Reflection and amplification Based DDoS Attacks
![[Pasted image 20240120215432.png]]
The original data may be very small(like a dns request eg 100 bytes) which may have a sizable response(say, 1000 bytes) Amplification.
Source Ip if spoofed, can result in a lot of traffic being transmitted to a victim which may not be able to handle it completely. (Reflection)
Detection at the DNS server layer becomes very difficult.
# Botnet
- Bot: A program performing automated task
	- a bot itself is not bad
- A botnet is a collection of computers, which are connected and work under the instruction of a master in order to accomplish something
	- typically botnets are used for committing computer crimes
- A botnet is controlled by a person or a group of people
- Usually has monetary interests
	- Spam mailing
	- Advertisement companies
## Components
- Command and Control Infrastructure.
	- Centralised: a centralised server gives commands to bots.
		- ![[Pasted image 20240120220522.png]]
		- single point of failure
	- Distributed
		- ![[Pasted image 20240120220613.png]]
		- works more autonomously.
		- Also called peer-to-peer.
		- commands from a central computer may be routed through the bots.
- Crucial
	- Have to maintain a stable connectivity
	- Robust
	- Persistence
	- status check of bots
	- reaction time
- Communication protocol
	- IRC Internet Relay chat
	- HTTP
	- TCP, DNs , SMB etc