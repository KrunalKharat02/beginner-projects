const setOfWords = ["My name is Mohit Kumar Suman and I want to become a entrepreneur",
"Hope you are having fun this is a simple game you van make", 
"If you want the source code of this game, Link is given in the description. you can create own version of this challenge", 
]

// only by press the start button, we can write into the text area otherwise it will be disable.

const msg = document.getElementById('msg');
const typeWords = document.getElementById('mywords');
const btn = document.getElementById('btn');
let startTime, endTime;

const playGame = ()=>{
   let randomNumber = Math.floor(Math.random()*3);
   // console.log(randomNumber);
   msg.textContent = setOfWords[randomNumber];
   let date = new Date();
   startTime = date.getTime();
   btn.textContent = 'Done'; 
   console.log(startTime);
}

const endPlay = ()=>{
   let date = new Date();
   endTime = date.getTime();
   let totalTime = ((endTime - startTime)/1000);
   console.log(totalTime);

   let totalStr = typeWords.value;
   let wordCount = wordCounter(totalStr);

   let speed = Math.round((wordCount / totalTime)*60);
   console.log(speed + " per minute");
   let finalMsg = "You typed total at " + speed + " words per Minute. ";
   finalMsg += compareWords(msg.innerText, totalStr);
   msg.innerText = finalMsg;
}

const compareWords = (str1, str2)=>{
   let words1 = str1.split(" ");
   let words2 = str2.split(" ");
   let cnt = 0;

   // arrayName then foreach then it will take whole function with value and index no. of that array.

   words1.forEach(function (item, index) {
      if(item == words2[index]){
         cnt++;
      }
   });

   let errorWords = (words1.length - cnt);
   return (cnt + " correct out of " + words1.length + " words and the total no of error are " + errorWords + ".");
}


const wordCounter = (str) =>{
   let response = str.split(" ").length;
   console.log(response);
   return response;
}

btn.addEventListener('click', function(){
   console.log(this);
   if(this.innerText == 'Start'){
      typeWords.disabled = false;
      playGame();
   }else if(this.innerText == 'Done'){
      typeWords.disabled = true;
      btn.innerText = 'Start'
      endPlay();
   }
});