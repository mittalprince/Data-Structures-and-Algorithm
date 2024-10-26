package com.example.communicationSystem;
public class Main {
    public static void main(String[] args) throws Exception {
        if(args.length != 1){
            System.out.println("Please provide a valid input file.");
            return;
        }
        CommandParser commandParser = new CommandParser();
        commandParser.processCommandFromFile(args[0]);
    }
}

/*
Input

addProvider Provider1 ACCOUNT1 EMAIL https://email.api.provider1.com/send emailUser1 pass123 true
addProvider Provider1 ACCOUNT1 SMS https://sms.api.provider1.com/send smsUser1 pass456 true
addProvider Provider2 ACCOUNT2 EMAIL https://email.api.provider2.com/send emailUser2 pass789 false
addProvider Provider2 ACCOUNT3 SMS https://sms.api.provider2.com/send smsUser2 pass789 false
processRequest EMAIL alice@example.com bob@example.com Meeting_Update Please_attend_the_meeting_at_10AM_tomorrow. true
processRequest SMS 1234567890 Your_OTP_is_1234 false
processRequest SOUNDBOX Store001 Welcome_to_the_store true
updateState Provider1 false
processRequest SMS 1234567890 Fallback_Test_OTP false
updateState Provider1 true
processRequest EMAIL carol@example.com dave@example.com Urgent_Update Project_deadline_moved_to_tomorrow. true
addProvider InvalidProvider ACCOUNT3 UNKNOWN https://invalid.api.provider.com/send invalidUser invalidPass false
processRequest UNKNOWN invalid@example.com invalidMessage Testing_Unknown_Channel false
updateState Provider1 false
processRequest EMAIL eve@example.com frank@example.com Critical_Alert Critical_system_failure_alert! true
processRequest SOUNDBOX Store002 New_promotion_announcement false
addProvider IncompleteProvider ACCOUNT4 SMS https://sms.api.noauth.com/send
updateState Provider1 false
updateState Provider2 false
processRequest SMS 2223334444 Testing_all_inactive_providers false
updateState Provider2 true
processRequest SMS 5556667777 System_restored_SMS_test false
*/

/*
output

Adding provider: Provider1 for account ACCOUNT1 channel EMAIL Critical true

Adding provider: Provider1 for account ACCOUNT1 channel SMS Critical true

Adding provider: Provider2 for account ACCOUNT2 channel EMAIL Critical false

Adding provider: Provider2 for account ACCOUNT3 channel SMS Critical false

Processing EMAIL request (Critical): true
Sending EMAIL request with providerId Provider1 to https://email.api.provider1.com/send with auth emailUser1 pass123
Email sent to bob@example.com with ACCOUNT1

Sending SMS request with providerId Provider2 to https://sms.api.provider2.com/send with auth emailUser2 pass789
SMS sent to 1234567890 with account ACCOUNT2

Unknown request type: SOUNDBOX
Disabling Provider1...

Sending SMS request with providerId Provider2 to https://sms.api.provider2.com/send with auth emailUser2 pass789
SMS sent to 1234567890 with account ACCOUNT2

Enabling Provider1...

Processing EMAIL request (Critical): true
Sending EMAIL request with providerId Provider1 to https://email.api.provider1.com/send with auth emailUser1 pass123
Email sent to dave@example.com with ACCOUNT1

Adding provider: InvalidProvider for account ACCOUNT3 channel UNKNOWN Critical false
No enum constant com.example.communicationSystem.ChannelType.UNKNOWN
No enum constant com.example.communicationSystem.ChannelType.UNKNOWN
Disabling Provider1...

Processing EMAIL request (Critical): true
Sending EMAIL request with providerId Provider2 to https://email.api.provider2.com/send with auth emailUser2 pass789
Email sent to frank@example.com with ACCOUNT2

Unknown request type: SOUNDBOX
Provider IncompleteProvider arguments
Disabling Provider1...

Disabling Provider2...

No active providers for this channel
Enabling Provider2...

Sending SMS request with providerId Provider2 to https://sms.api.provider2.com/send with auth emailUser2 pass789
SMS sent to 5556667777 with account ACCOUNT2

*/