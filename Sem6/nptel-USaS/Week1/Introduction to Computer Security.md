# Prerequisites
Computer Networks
Operating Systems
Working Knowledge of Linux Operating system
Knowing Perl/Shell Scripting

![[Pasted image 20240120202843.png]]


# What is Computer Security
Deals with the art of protecting computing resources like:
- Memory
- Computing Power
- Data

Protection Against:
- Human Errors ( organic user errors )
- Bad Guys outside ( hackers )
- Dishonest people inside ( Insider Threats )

# When to say System is Secure
All systems have some function which requires an input and provides an output.
A system is said to be secure if it possesses the following two properties:
- For an expected input supplied with good intent it generates a desired output.
- For an unexpected input supplied with malicious intent it does not fail/crash.

# Why should we care for security
For utilities like:
- Online Banking
- Online shopping
- Booking tickets, etc

and storing data like:
- Photographs
- Videos
- Sensitive Documents

Privacy and Security in handling is absolutely necessary.

If your device gets hacked, it might end up being used in another cyber shenanigan and you will end up in trouble.

Reputation and Credibility of Organisations get affected.

# Who are Vulnerable to Attacks
- Financial Institutions
- Defence Organisations
- Government Agencies
- Pharma
- IT 
- Intellectual property Management companies
- Academic Institutions
- Everyone connected to the Internet

# CIA Principles of Security
## Confidentiality
Avoiding unauthorised disclosure of information

 - Provide access to legitimate users
 - Block access to Illegitimate users

### Can be achieved through:
#### Encryption
Transform data to meaningless unit for transmission and storage. Show it correctly to intended users.
#### Access Control
Control who can claim access to data

#### Authentication
Determining the identity of person claiming access.
Can be done through:
- Something the person has (email,mob number, OTP)
- Something that the person knows( passwords )
- Something the person is (Biometrics)
#### Authorisation
Determining whether the person is allowed to access something
#### Physical Security
Establishing Physical barriers
## Integrity
An assurance that information is not altered midway of transmission

![[Pasted image 20240120205011.png]]

Integrity Compromise:
- Systems induced: hardware flips a bit
- Malicious: someone rewrites data
### Can be achieved through:
#### Confidentiality protection techniques also protect integrity
#### Backup
Periodically archive data
#### Checksum
Computing something out of data
#### Error Correction Code
Can correct errors up to a limit

#### **Metadata also needs protection**
- Owner
- Size of File
- Last Read and write timings
- Location of Data

## Availability
An assurance of information access and modification in a reasonable time frame

**Timely Delivery is important**
- Stock quotes
- Banking transactions
### Can be Achieved through:
#### Physical Protection
- guards
- fire management systems
- locks
#### Redundancy in computing
- RAID
- Fault tolerance systems

# The Value of Your Data
Assess that if some particular data is compromised/lost what are the implications
### Lost data
- Financial loss
### Confidential data
- Danger of going into wrong hands
### Downtime
- Calling a customer care service which says my service is down
- Doesn't carry good image
### Staff Time
- Time invested in repairing and fixing the issue
### Reputation
- Damage
- Financial Loss

# Security Mechanism
## Golden Principles of Designing security  systems
`Developer's  end`
#### Economy of mechanism
The Easier and simple(in design) a security mechanism, the better it is to understand
#### Fail-Safe Defaults
Default config should be conservative (strict security)
#### Complete Mediation
A Security Authority should check every action of a user
#### Open Design
Security design should be made public so that it gets public scrunity, matures over time
#### Separation of privilege
Multiple conditions should be required to get access. separation should be well defined.
#### Least Privilege
Every program must have bare minimum privileged to run.
#### Least common mechanism
Sharing among users should be minimum.
#### Psychological acceptability
User Interfaces should be intuitive
accessible to non tech savvy people
#### Compromise recording
Sometimes its most desirable to record details of the attacker rather than designing a comprehensive security mechanism.
Log maintenance.

