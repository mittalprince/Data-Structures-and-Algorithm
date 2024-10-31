package factory;

import domain.ChannelType;
import request.EmailRequest;
import request.Request;
import request.SMSRequest;
import request.SoundBoxRequest;

public class RequestFactory {
    public Request getRequest(ChannelType requestType) {
        return switch (requestType) {
            case EMAIL -> new EmailRequest();
            case SMS -> new SMSRequest();
            case SOUNDBOX -> new SoundBoxRequest();
        };
    }
}
