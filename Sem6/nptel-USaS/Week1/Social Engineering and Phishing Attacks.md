![[Pasted image 20240121165636.png]]

**Social Engineering**
A method to stage a cyber attack through human interaction and errors
##### Stages:
- Investigation: Preparing ground
- Hook: Gain Foothold
- Play: Expand the foothold
- Exit: Erase all traces
# Case Study
![[Pasted image 20240121165741.png]]

# Types
- Baiting: Make a false promise to trick user to do something
	- ex, Leave a flash drive in a place
- ScareWare: Falsely bombard the user with scary messages
	- eg, Your account will be deleted if you do not verify
- Phishing: Trick user to reveal sensitive information
	- eg. Collect user credentials through lookalike websites
# Phishing
made up of :
- Phreaking + Fishing
- Phreaking --> Making free calls in the 70s
- Fishing --> Attract the fish to bite
- Those who bite, become victims

1. form of a social engineering attack
	1. not all social engineering attacks are phishing attacks
2. Mimic the communication and appearance of another legitimate communication and companies
3. Attractive targets include:
	1. Financial Institutions
	2. Gaming Industry
	3. Social Media
	4. Security Companies
## Flow
- Mail Sender: sends large volume of fraudulent emails
- Collector: collects sensitive information from users
- Casher: use the collected sensitive information to en-cash

# Forms of Phishing
- Misspelled URLs
	- www.sbibank.statebank.com
	- www.micosoft.com
	- www.mircosoft.com
- Anchor Text
	- A link says that its linked to microsoft.com but the actualy `<a href>`  tag has some other URL there.
- Fake SSL Lock
	- Simply show it so that users feel secure
- Getting valid certificates to illegal sites
	-  Certifying agency not being alert
	- ![[Pasted image 20240121171722.png]]
	- Sometimes users overlook security certificate warnings

# Payloads
- Keyloggers
- Spyware
- Screen Grabber
- Bot

# Purpose
- Login credentials
- Banking credentials
- Credit card details
- Address and personal information
- Trade secrets
- DDoS agent
- Botnet growth
- Confidential documents
# Types of Phishing
## Clone Phishing
- Phisher creates a clone email
- By getting contents and addresses of recipients and sender
## Spear Phishing
- Targeting a specific group of users
- All Users of that group have something in common
	- Targeting all faculty members of a department
## Phone Phishing
- Call someone and say you are from bank
- Ask for password saying you need to do maintenance
## Email Spoofing
- An email concealing its true source
	- eg coming from customerservice@sbi.com while its actually not.
- Send an email saying your bank account needs to be verified immediately
- User believes and sends details
- Spoof email generators are vv common.
# Phishing today
- Use bots to perform large scale activity
	- Relays for sending spam and phishing emails
- Phishing Kits
	- Ready to use
	- Contains clones of many banks and other websites
- Uncommon encoding mechanisms
- Fake banner advertisements
## Dynamic Code
- phishing emails contain links to sites whose contents change
- When email came in midnight it was ok but next day when you clicked it is spreading malware
## IP address instead of Domain Name
- 200.100.100.200
## Use of Targeted email
- Gather enough enough information about user from social networking sites
- Send a targeted email using the knowledge from previous step
- Unsuspecting user clicks on link
- Attacker takes control of recipient machine (backdoor, trojan)
- Steal/harvest credentials
# Personal Level Protection
- Email Protection Mechanisms
	- Blocking dangerous email attachments
	- Disable HTML capability in all emails
- Awareness and education
- Web Browser toolbars
	- connect to a database of FQDN IP address mapping of phishing sites
- Multi Factor Authentication
# Enterprise Level Protection
- Collecting data from users
	- About emails received
	- Website links
	- Why any one should give you data
		- Their interests also included
		- Incentives
- Analysing spam emails for keywords
	- click on the link below
	- enter user name password here
	- account will be deleted etc
- Personalisation of emails
	- Every email should quote some secret that proves identity
	- ex Phrase as Mr Sid and not Dear User
