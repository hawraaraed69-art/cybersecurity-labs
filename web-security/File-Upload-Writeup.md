# Lab: File Upload Vulnerability

## Scenario
The objective was to exploit an unrestricted file upload vulnerability to gain Remote Code Execution (RCE) on the web server.

## Tools Used
* **Burp Suite** (Proxy & Repeater)
* **Kali Linux**

## Steps Taken
1. **Interception:** Used Burp Suite to intercept the upload request.
2. **Bypassing Protections:** Modified the `Content-Type` header and file extension to bypass server-side filters.
3. **Execution:** Uploaded a basic PHP web shell to execute system commands.
4. **Impact:** Successfully accessed the server's internal files.

## Mitigation
To prevent this, the server should implement strict file type validation and rename uploaded files using a random naming convention.
