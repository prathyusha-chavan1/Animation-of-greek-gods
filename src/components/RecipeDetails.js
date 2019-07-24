import React from 'react';
import { Link } from 'react-router-dom';


const apikey=process.env.REACT_APP_API_KEY;
//const apikey="2cd5e109c01f5f3e1ee8cd147cf4eb34";//pt
//const apikey = "0939cb446f8d93887b726f19456576b1";//pu
class RecipeDetails extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      recipe: null
    };
  }
  componentDidMount() {
    console.log("inside rd", this.props);
    this.searchRecipe(this.props.match.params.id);
  }
  searchRecipe(recipeId) {
    fetch(`https://www.food2fork.com/api/get?key=${apikey}&rId=${recipeId}`)
      .then(response => response.json())
      .then(data => this.setState({
        recipe: data.recipe

      }));
  }

  render() {

    if (this.state.recipe) {
      const { image_url, recipe_id, title, publisher, source_url, ingredients } = this.state.recipe;
      return (

        <div className="container">
          <div className="active-recipe">
          <img  className="active-recipe__img"src={image_url} alt={recipe_id} />
          <h3 className="active-recipe__title">{title}</h3>
          <h4 className="active-recipe__publisher">{publisher}</h4>
         

          <p className="active-recipe__website">website:
          <span> <a href={source_url} target="_blank" rel="noopener noreferrer">{source_url}</a></span></p>
          <ol>
            
            {
              ingredients.map((ingredient, index) => (<li key={index}>{ingredient}</li>))
            }

          </ol> 
          <button className="active-recipe__button">
          <Link to="/">HOME</Link>
          </button>
          </div>
        </div>
      );
    }

    return (
      <p>Fetching details</p>
    );
  }
}
export default RecipeDetails;