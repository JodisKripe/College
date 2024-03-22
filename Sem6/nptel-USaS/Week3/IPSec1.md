![[Pasted image 20240322230258.png]]
Takes IP Datagram/packet -> does modifications and sends over the Network.
# Features
![[Pasted image 20240322230447.png]]
![[Pasted image 20240322230548.png]]
The best Use Case is Using it with a VPN.
![[Pasted image 20240322230816.png]]
Middlebox is more prominently used since its more efficient.
![[Pasted image 20240322230922.png]]
Offloading all the functionality to the perimeter devices.
![[Pasted image 20240322230959.png]]
AH -> Authentication
ESP -> Authentication and Confidentiality
![[Pasted image 20240322231103.png]]
Transport mode --> original header is kept as it is and a new header is added in the middle of the packet
The original layering of the packet is not changed and the routers can function as usual
![[Pasted image 20240322231146.png]]
Tunnel Mode --> a header is added to the beginning of the packet.  Encapsulation is done.
The new IP header can have the IP of the Middlebox and the Tertiary network devices would never know who the exact sender or recipient of the packet was withing the network.
![[Pasted image 20240322231254.png]]

