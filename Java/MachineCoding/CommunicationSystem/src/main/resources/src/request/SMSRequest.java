package request;

import domain.ChannelType;

public class SMSRequest extends Request {
    String phone;
    public void enterDetails(String phone, String message) {
        this.message = message;
        this.phone = phone;
        this.channelType = ChannelType.SMS;
        validate();
    }

    @Override
    boolean validate() {
        return isOnlyNumbers(this.phone);
    }

    static boolean isOnlyNumbers(String input) {
        return input != null && input.matches("\\d+");
    }
}
