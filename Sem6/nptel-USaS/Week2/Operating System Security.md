- Security Concerns in OS
- Process Security
- File Security

![[Pasted image 20240322194415.png]]
Concerns
- Personal files
- One user/process/application tampering with another

![[Pasted image 20240322194826.png]]

time slicing => time sharing 
![[Pasted image 20240322194947.png]]

init runs first in a linux env and it is responsible for creating other child processes hierarchically. children often borrow resources from parent and the all applications running user or system are basically in the process tree of `init`
`fork + exec` -> New duplicate child + modified execution command 