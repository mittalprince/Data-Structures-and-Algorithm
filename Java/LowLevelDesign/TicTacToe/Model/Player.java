package LowLevelDesign.TicTacToe.Model;
import TicTacToe.Model.PlayingPiece;
class Player{
    public String name;
    public PlayingPiece playingPiece;

    public String getName(){
        return this.name;
    }
    public PlayingPiece getPlayingPiece() {
        return playingPiece;
    }

    public void setPlayingPiece(PlayingPiece playingPiece) {
        this.playingPiece = playingPiece;
    }

}