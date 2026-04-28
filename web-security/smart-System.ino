// --- Arduino Security System: Password Protected Access ---

String password = "1234";
int greenLED = 8;
int redLED = 9;
int buzzer = 10;

int attempts = 0;
int maxAttempts = 3;

void setup() {
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.println("System Initialized...");
  Serial.println("Enter Password:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (attempts < maxAttempts) {
      if (input == password) {
        // --- Access Granted Logic ---
        Serial.println("Access Granted");
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        
        tone(buzzer, 1000);
        delay(1000);
        noTone(buzzer);
        
        attempts = 0; // Reset attempts on success
      } 
      else {
        // --- Wrong Password Logic ---
        attempts++;
        Serial.print("Wrong Password! Attempts: ");
        Serial.println(attempts);
        
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
        
        tone(buzzer, 300);
        delay(500);
        noTone(buzzer);

        if (attempts >= maxAttempts) {
          // --- System Lockdown ---
          Serial.println("System Locked!");
          
          for (int i = 0; i < 5; i++) {
            tone(buzzer, 500);
            delay(300);
            noTone(buzzer);
            delay(300);
          }
          
          delay(5000); // 5 seconds lockout period
          attempts = 0; // Reset after lockout
          Serial.println("Try Again:");
        }
      }
    }
  }
}
