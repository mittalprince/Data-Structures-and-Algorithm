package domain;

import java.util.List;

public class Account {
    String username;
    String password;

    List<ChannelType> channelType;

    public Account(String username, String password, List<ChannelType> channelType) {
        this.username = username;
        this.channelType = channelType;
        this.password = password;
    }

    public List<ChannelType> getChannelType() {
        return channelType;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }
}
