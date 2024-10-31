package request;

import domain.ChannelType;

public class EmailRequest extends Request {

    String sender;
    String receiver;
    String subject;

    public void enterDetails(String message, String sender, String reciever, String subject) {
        this.message = message;
        this.receiver = reciever;
        this.sender = sender;
        this.subject = subject;
        this.channelType = ChannelType.EMAIL;
        validate();
    }

    @Override
    boolean validate() {
        return !this.sender.equals(this.receiver);
    }
}
