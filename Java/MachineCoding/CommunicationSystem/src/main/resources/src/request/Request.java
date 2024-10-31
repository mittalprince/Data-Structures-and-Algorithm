package request;

import domain.ChannelType;

public abstract class Request {
    public String message;
    public ChannelType channelType;
    abstract boolean validate();
}
