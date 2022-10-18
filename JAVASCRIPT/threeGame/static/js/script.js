//Challenge 1: Your age in Days

function ageInDays() {
  var birthYear = prompt("In which Year you have born?");
  var ageInDayss = (2021 - birthYear) * 365;
  var h1 = document.createElement("h1");
  var textAnswer = document.createTextNode(
    "You are " + ageInDayss + " days old"
  );
  h1.setAttribute("id", " ageInDayss");
  h1.appendChild(textAnswer);
  document.getElementById("flex-box-result").appendChild(h1);
  console.log(textAnswer);
}

function reset() {
  var Erase = " ";
  document.getElementById("flex-box-result").innerHTML = Erase;
}

//Challenge 2: Cat generator
function generateCat() {
  var image = document.createElement("img");
  image.src = "static/images/bg.png";
  document.getElementById("flex-cat-gen").appendChild(image);
}

//Challenge 3: Rock, paper, scissors
function rpsGame(yourChoice) {
  console.log(yourChoice);
  var humanChoice, botChoice;
  humanChoice = yourChoice.id;
  botChoice= numberToChoice(randToRpsInt());
  console.log('computerChoice: ',botChoice);
  
  results = decideWinner(humanChoice, botChoice); 
  console.log(results); //[0.5, 0.5], [0,1]
  
  message  = finalMessage(results); 
  console.log(message);
  rpsFrontEnd(yourChoice.id, botChoice, message);
}

function randToRpsInt() {
  return Math.floor(Math.random() * 3);
}

function numberToChoice(number) {
  return ["rock", "paper", "scissors"][number];
}
  
function decideWinner(yourChoice, computerChoice){
   var rpsDatabase = {
      'rock': {'scissors': 1, 'rock': 0.5, 'paper': 0},
      'paper':{'rock': 1, 'paper': 0.5, 'scissors': 0},
      'scissors':{'paper': 1, 'scissors': 0.5, 'rock': 0}
   }

   var yourScore = rpsDatabase[yourChoice][computerChoice];
   var computerScore = rpsDatabase[computerChoice][yourChoice];

   return[yourScore, computerScore];
}

function finalMessage([yourScore, computerChoice]){
   if (yourScore === 0){
      return {'message': 'you lost!', 'color': 'red'};
   }
   else if (yourScore === 0.5) {
      return {'message': 'you tied!', 'color': 'yellow'};
   }
   else {
      return {'message': 'you Won!', 'color': 'green' };
   }
}

function rpsFrontEnd(humanImageChoice, botImageChoice, finalMessage){
   var imagesDatabase = {
      'rock': document.getElementById('rock').src,
      'paper': document.getElementById('paper').src,
      'scissors': document.getElementById('scissors').src
   }
   
   // let's remove all the images
   document.getElementById('rock').remove();
   document.getElementById('paper').remove();
   document.getElementById('scissors').remove();

   var humanDiv = document.createElement('div');
   var botDiv = document.createElement('div');
   var message = document.createElement('div');

   humanDiv.innerHTML = "<img src='" + imagesDatabase[humanImageChoice] + "'height=150 width=150 style='box-shadow: 0px 10px 50px rgba(37, 50, 233, 11)';>"
   message.innerHTML = "<h1 style='color: "+ finalMessage['color'] + "; font-size: 60px; padding: 30px; '>" + finalMessage['message'] + "</h1>"
   botDiv.innerHTML = "<img src='" + imagesDatabase[botImageChoice] + "'height=150 width=150 style='box-shadow: 0px 10px 50px rgba(243, 38, 24, 1)';>"
   
   document.getElementById('flex-box-rps-div').appendChild(humanDiv);
   document.getElementById('flex-box-rps-div').appendChild(message);
   document.getElementById('flex-box-rps-div').appendChild(botDiv);

   // append meaning>> add something to the end of a written document
}


// Challenge 4: Change the color of the buttons

// getELementsByTagName will return an array containing all buttons

var all_buttons = document.getElementsByTagName('button');
console.log(all_buttons);

var copyAllButtons = [];
for (let i=0; i<all_buttons.length; i++){
   copyAllButtons.push(all_buttons[i].classList[1]);
}
console.log(copyAllButtons);



function buttonColorChange(buttonThingy) {
   // console.log(buttonThingy.value);
   if (buttonThingy.value === 'red') {
      buttonsRed();
   }
   else if (buttonThingy.value === 'green') {
      buttonsGreen();
   }
   else if (buttonThingy.value === 'reset') {
      buttonsColorReset();
   }
   else if (buttonThingy.value === 'random') {
      randomColors();
   }
} 

function buttonsRed() {
   for (let i=0; i<all_buttons.length; i++){
      all_buttons[i].classList.remove(all_buttons[i].classList[1]);
      all_buttons[i].classList.add('btn-danger');
   }
}

function buttonsGreen() {
   for (let i=0; i<all_buttons.length; i++){
      all_buttons[i].classList.remove(all_buttons[i].classList[1]);
      all_buttons[i].classList.add('btn-success');
   }
}

function buttonsColorReset() {
   for (let i=0; i<all_buttons.length; i++){
      all_buttons[i].classList.remove(all_buttons[i].classList[1]);
      all_buttons[i].classList.add(copyAllButtons[i]);
   }
}

function randomColors(){
   var choices = ['btn-primary', 'btn-danger', 'btn-success', 'btn-warning', 'btn-secondary', 'btn-dark', 'btn-info'];
   for (let i=0; i<all_buttons.length; i++){
      let randomChoices = choices[Math.floor(Math.random()*7)];
      all_buttons[i].classList.remove(all_buttons[i].classList[1]);
      all_buttons[i].classList.add(randomChoices);
   }
   console.log(randomChoices);

}


// Challenge-5> Blackjack game

let blackjackGame = {
   'you':{'scoreSpan': '#your-blackjack-result', 'div': '#your-box', 'score': 0},

   'dealer':{'scoreSpan': '#dealer-blackjack-result', 'div': '#dealer-box', 'score': 0},

   'cards':['2', '3', '4', '5', '6', '7', '8', '9', '10', 'K', 'Q', 'J', 'A'],

   'cardsMap':{'2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '10':10, 'K':10, 'Q':10, 'J':10, 'A':[1, 11]},

   'wins' : 0,
   
   'losses' : 0,

   'draws' : 0,
};

const YOU = blackjackGame['you'];
const DEALER = blackjackGame['dealer'];
const hitSound = new Audio('static/sound/swish.m4a');
const winSound = new Audio('static/sound/cash.mp3');
const lostSound = new Audio('static/sound/aww.mp3');

document.querySelector("#blackjack-hit-button").addEventListener('click', blackjackHit);

document.querySelector("#blackjack-stand-button").addEventListener('click', dealerLogic)

document.querySelector("#blackjack-deal-button").addEventListener('click', blackjackDeal)

function blackjackHit(){
   let card = randomCard();
   console.log(card);
   showCard(card, YOU);
   // showCard(DEALER);
   updateScore(card, YOU);
   console.log(YOU['score']);
   showScore(YOU);
}

function randomCard(){
   let randomIndex = Math.floor(Math.random()*13);
   return blackjackGame['cards'][randomIndex];
}

function showCard(card, activePlayer) {
   if(activePlayer['score']<=21){
   let cardImage = document.createElement('img');
   cardImage.src = `static/images/${card}.png`;
   document.querySelector(activePlayer['div']).appendChild(cardImage);
   hitSound.play();
   }
}

function blackjackDeal(){
   // showResult(computeWinner());
   let yourImages = document.querySelector('#your-box').querySelectorAll('img');
   let dealerImages = document.querySelector('#dealer-box').querySelectorAll('img');

   for (i=0; i< yourImages.length; i++){
      yourImages[i].remove();
   }
   for (i=0; i< dealerImages.length; i++){
      dealerImages[i].remove();
   }

   YOU['score'] = 0;
   DEALER['score'] = 0;

   document.querySelector('#your-blackjack-result').textContent = 0;
   document.querySelector('#dealer-blackjack-result').textContent = 0;
   document.querySelector('#your-blackjack-result').style.color = 'white';
   document.querySelector('#dealer-blackjack-result').style.color = 'white';
   document.querySelector('#blackjack-result').textContent = 'Let\'s Play';
   document.querySelector('#blackjack-result').style.color = 'black';

}

function updateScore(card, activePlayer) {
   // if adding 11 keeps me below 21 , add 11. Othwise, add 1
   if(card === 'A') {
      if(activePlayer['score'] + blackjackGame['cardsMap'][card][1] <=21){
          activePlayer['score'] += blackjackGame['cardsMap'][card][1];
      } else{
          activePlayer['score'] += blackjackGame['cardsMap'][card][0];
      }
  }else{
     activePlayer['score'] += blackjackGame['cardsMap'][card];
  }
}

function showScore(activePlayer) {
   if(activePlayer['score']  > 21){
       document.querySelector(activePlayer['scoreSpan']).textContent = 'BUST!';
       document.querySelector(activePlayer['scoreSpan']).style.color = 'red';
   }else{
      document.querySelector(activePlayer['scoreSpan']).textContent = activePlayer['score'];
   }
}

function dealerLogic(){
   let card = randomCard();
   showCard(card, DEALER);
   updateScore(card, DEALER);
   showScore(DEALER);

   if(DEALER['score'] > 15){
      let winner = computeWinner();
      showResult(winner);
   }
}

// compute winner and who just won
// update the wins draws and losses
function computeWinner(){
  let winner;
  if (YOU['score'] <= 21){
     // conditon : higher score than dealer or when dealer busts but you are 21 or under
     if(YOU['score'] > DEALER['score'] || DEALER['score'] > 21){
        console.log("You Won!");
        blackjackGame['wins']++;
        winner = YOU;

     }else if(YOU['score'] < DEALER['score']){
        console.log("You Lost!");
        blackjackGame['losses']++;
        winner = DEALER;

     }else if(YOU['score'] === DEALER['score']){
        blackjackGame['draws']++;
        console.log("You Drew!");
     }

     // condition when user busts when dealer doesn't
  }else if(YOU['score'] > 21 && DEALER['score'] <= 21){
     console.log('You Lost!');
     blackjackGame['losses']++;
     winner = DEALER;

     // conditon: When you and Dealer busts
  }else if(YOU['score'] > 21 && DEALER['score'] > 21){
     console.log('You Drew!');
     blackjackGame['draws']++;
  }
  console.log('winner is', winner);
  console.log(blackjackGame);
  return winner;
}

function showResult(winner) {
   let message, messageColor;
   if (winner == YOU){
      document.querySelector('#wins').textContent = blackjackGame['wins'];
      message = 'You Won!';
      messageColor = 'green';
      winSound.play();
   }else if (winner === DEALER){
      document.querySelector('#losses').textContent = blackjackGame['losses'];
      message = 'You Lost!';
      messageColor = 'red';
      lostSound.play();
   }else{
      document.querySelector('#draws').textContent = blackjackGame['draws'];
      message = 'You Drew!';
      messageColor = 'black';
   }

   document.querySelector('#blackjack-result').textContent = message;
   document.querySelector('#blackjack-result').style.color = messageColor;

}


