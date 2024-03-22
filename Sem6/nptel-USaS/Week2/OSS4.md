#### Problems with plain hashing
- If two users select the same password then their hashes are also the same.
- Looking at the hashes will let everyone know.

#### Salting
![[Pasted image 20240322203237.png]]
Add random number to the password and then hash
![[Pasted image 20240322203404.png]]
![[Pasted image 20240322203703.png]]
![[Pasted image 20240322203824.png]]
! and * determine that user cannot login using a password
! -> password can be set.
![[Pasted image 20240322204129.png]]
## Attacks on Password based Auth
![[Pasted image 20240322204419.png]]
![[Pasted image 20240322204548.png]]
Put all possible salt values and then hash.
![[Pasted image 20240322204724.png]]
BruteForce
