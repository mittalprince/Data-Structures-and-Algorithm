package request;

import domain.ChannelType;

public class SoundBoxRequest extends Request {

    String language;
    public void enterDetails(String message, String language) {
        this.message = message;
        this.language = language;
        this.channelType = ChannelType.SOUNDBOX;
        validate();
    }
    @Override
    boolean validate() {
        return switch (language) {
            case "Hindi", "English" -> true;
            default -> false;
        };
    }
}
