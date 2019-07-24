import React from 'react';
import Search from './components/Search';
import Recipes from './components/Recipes';

import './App.css';


const apikey=process.env.REACT_APP_API_KEY;//pt
//pt

//const apikey = "0939cb446f8d93887b726f19456576b1";//pu
class App extends React.Component {
  constructor(props){
    super(props);
    this.searchRecipe=this.searchRecipe.bind(this);

    this.state = {
     recipes: []
    }
  } 
  
  searchRecipe(recipeName)
  {
    fetch(`https://www.food2fork.com/api/search?key=${apikey}&q=${recipeName}`)
    .then(response=>response.json())
    .then(data=>this.setState({
       recipes: data.recipes
      
     }));
  
}
render(){

  return (
    <div className="App"> 
    <header className="App-header">
    <h2 className="App-title">Recipe search</h2>
    </header>
      
      <Search  onSubmit={this.searchRecipe} />     

      <Recipes recipes={this.state.recipes}
       /> 
      

   </div>
   
     
  );
  }
}

export default App;
