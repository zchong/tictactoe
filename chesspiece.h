/*  Author:Zhia Chong
    File: chesspiece.h
*/

class chesspiece {
    public:
        chesspiece();
        chesspiece(char piece);
        char getPieceLabel();
        void setPieceLabel(char chesspiece);
    private:
        char pieceLabel;
};