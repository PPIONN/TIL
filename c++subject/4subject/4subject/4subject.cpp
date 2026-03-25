#include <iostream>
#include <vector>
#include <string>

 //PotionRecipe class 정의
class PotionRecipe
{
public:
    // 멤버변수를 초기화
    PotionRecipe(const std::string& potionName, const std::string& coreIngredient) {
        potionName_ = potionName;
        coreIngredient_ = coreIngredient;

    };

    // 멤버 변수에 접근하기 위한 Getter 함수
    const std::string& GetPotionName() const { return potionName_; };
    const std::string& GetCoreIngredient() const { return coreIngredient_; };

private:
    std::string potionName_;
    std::string coreIngredient_;
};

// AlchemyWorkshop class 정의
class AlchemyWorkshop
{
public:
    // 새로운 레시피를 recipes 벡터에 추가, push_back()
    void AddRecipe(const std::string& potionName, const std::string& coreIngredient) {
        recipes_.push_back(PotionRecipe(potionName, coreIngredient));
    };

    // 모든 레시피의 이름과 핵심 재료 출력
    // for (const PotionRecipe& r : recipes_) <- range-for 구문
    void DisplayAllRecipes() const {
        for (const PotionRecipe& r : recipes_) {
            std::cout << r.GetPotionName() << r.GetCoreIngredient() << std::endl;
        }
    };

    // 이름으로 레시피 검색(range-for, == 를 활용해보자)
    // - 예외처리 : 동일한 이름이 없을 경우 어떻게 처리할지는 자유
    // PotionRecipe("NONE", "NONE"); ? 
    PotionRecipe SearchRecipeByName(const std::string& name) const {
        for (const PotionRecipe& r : recipes_) {
            if (r.GetPotionName() == name) {
                return r;
            }
        }
        return PotionRecipe("NONE", "NONE"); // 못 찾은 경우
    };

    // 특정 재료를 사용하는 모든 레시피 검색(range-for, == 를 활용해보자)
    // - 결과가 여러 개일 수 있음
    // - 예외처리 : 결과가 없을 경우 어떻게 처리할지는 자유(위와 비슷하게 해보자)
    std::vector<PotionRecipe> SearchRecipeByIngredient(const std::string& ingredient) const {
        std::vector<PotionRecipe> result;
        for (const PotionRecipe& r : recipes_) {
            if (r.GetCoreIngredient() == ingredient) {
                result.push_back(r);
            }
        }

        return result;
    };

private:
    std::vector<PotionRecipe> recipes_;
};


int main()
{
    AlchemyWorkshop workshop;

    // 레시피 추가
    workshop.AddRecipe("Healing Potion", "Herb");
    workshop.AddRecipe("Mana Potion", "Magic Water");
    workshop.AddRecipe("Stamina Potion", "Herb");
    workshop.AddRecipe("Fire Resistance Potion", "Fire Flower");

    // 전체 레시피 출력
    workshop.DisplayAllRecipes();

    // 이름으로 레시피 검색
    PotionRecipe recipe = workshop.SearchRecipeByName("Mana Potion");
    std::cout << "검색된 레시피: "
        << recipe.GetPotionName() << std::endl;

    // 재료로 레시피 검색
    std::vector<PotionRecipe> herbRecipes =
        workshop.SearchRecipeByIngredient("Herb");

    std::cout << "Herb를 사용하는 레시피 수: "
        << herbRecipes.size() << std::endl;

    return 0;
}
