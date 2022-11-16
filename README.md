# Smart-Voting-System-
Smart Voting System Using RFID Cards, Fingerprint &amp; Facial Recognition 

In this smart voting system project, we'll be having 3 verification process and considered it as 3 phases of voting system.And adopted a buzzer, if any of these verification phases fails buzzer will gwt activated and beep for few seconds(here i have kept for 7 sec,it can be modified in code as per our wish).

*Phase 1:* Includes RFID Card reader, that verifies the details of voter which is Pre-loaded before voting happens. It's just like a smart card(like metro card) we just need to tap the card on reader, it works on *Radio Frequency Identification.* It replace the current Voting card.

*Phase 2:* After RFID card verification, Fingerprint module will pops up, We'll be preloaded the voter's fingerprints before the voting day. If eligible voter's details are present in the database it will permit him to the next phase of verification process else it will declare him/her as unauthorized voter.

*Phase 3:* Facial Recognition using Opencv technologies and numpy. After 2 successful verification process this finl stage of verification process appears, eligible voter will be detected via web cam, if that details are present in the database it will permit authorized voter to cast his/her voting else it will declare him/her as unauthorized person.

If all the three levels are matched then the door of ballot booth opens for the voter to cast the vote.If not the voter is barred from
voting. Also the results are simultaneously displayed on the monitor.


*INTENTION Behind this Project:*

The main aspect of democracy of a nation is the VOTE by which people elect their favorite candidate to rule the nation. Intervention of illegal practices will lead the nation to wrong hands. There are several methods adopted by the government to avoid crimes during voting. But the untouched area without proper security is the verification process. This project mainly helps in resolving difficulties and crimes involved in verification process.

So by implementing this smart voting system we can reduce Malfunctioning in areas which are not under secured government. And we can reduce the actual time that we're spending in real time senario's. This secured verification process prevents proxies, political party intervention and other crime activities during the Election Day.


*Libraries to be installed:*

1. pip install cmake

2. pip install opencv-python

3. pip install dlib

4. pip install face_recognition

Snapshots:

Authorized Voter


![authorised](https://user-images.githubusercontent.com/82816210/202089574-741d6f77-b21f-49b1-b413-d2a14d1f18ca.png)


Unauthorized Voter


![unauthorized](https://user-images.githubusercontent.com/82816210/202089615-a3292731-fb25-4549-bfed-d07deebfdbec.png)


