![[Pasted image 20240322211138.png]]
![[Pasted image 20240322211414.png]]
Symmetric Encryption

![[Pasted image 20240322211528.png]]
Asymmetric Encryption

![[Pasted image 20240322211759.png]]
private key used to calculate signature.
now the signature is sent along with the email
So the recipient can verify by decrypting the Signature with the public key to get the digest and recalculate the Digest from the received message and compare. The recipient can be then assured that the Message received is indeed sent by the authentic sender and has not been manipulated.

### How emails are sent
![[Pasted image 20240322212137.png]]
### Structure
![[Pasted image 20240322212334.png]]
Headers as well as the message should not be manipulated in transit.
### SMTP
![[Pasted image 20240322212501.png]]
# MIME
*Multipurpose Internet Mail Extensions*
![[Pasted image 20240322212631.png]]

![[Pasted image 20240322212739.png]]
Secure MIME
All features of MIME retained as well.
![[Pasted image 20240322212823.png]]
![[Pasted image 20240322212857.png]]
No Encryption, only hashing
![[Pasted image 20240322213005.png]]
Hash is signed with the private key.
![[Pasted image 20240322213137.png]]
![[Pasted image 20240322213432.png]]
![[Pasted image 20240322213500.png]]
![[Pasted image 20240322213524.png]]
![[Pasted image 20240322213618.png]]
#### S/MIME Limitation
![[Pasted image 20240322213634.png]]
- Everyone needs public/private keys(end user usability issue)
- S/MIME does not prevent the recipient from claiming that the email never reached them. Recipient can deny it.
- sending emails to multiple people involves replicating the message and making digests for each user in the TO: list
- Email headers can get altered. S/MIME provides security only to the email body since the digest etc which are only calculated for the message body.
# DomainKeys Identified Mail (DKIM)
![[Pasted image 20240322214038.png]]
Only provides Authenticity of the sender.
![[Pasted image 20240322214257.png]]
All the senders from gmail.com can now send emails without ever having to worry about the cryptography.
All the encryption is now offloaded to the domain. Digest Attachment as well as verification of the digest value.
Emails' domains are judged, not the individual here.
![[Pasted image 20240322214502.png]]
![[Pasted image 20240322214808.png]]
S/MIME and DKIM can work together as well.

